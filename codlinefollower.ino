#include <QTRSensors.h>

//TODO: Inlocuiti x cu pinul la care este conectat pe Arduino
const unsigned int MOTOR1A = x;
const unsigned int MOTOR1B = x;
const unsigned int MOTOR2A = x;
const unsigned int MOTOR2B = x;

const unsigned int LINIE1 = x;
const unsigned int LINIE2 = x;
const unsigned int LINIE3 = x;
const unsigned int LINIE4 = x;
const unsigned int LINIE5 = x;
const unsigned int LINIE6 = x;
const unsigned int LINIE7 = x;
const unsigned int LINIE8 = x;
//ENDTODO

//PID
const float KP = 0.5;
const float KD = 0.0;
const float KI = 0.0;

double last_p = 0;
double integral = 0;
//ENDPID

const int SPEED = 30;

QTRSensorsRC qtr((unsigned char[]) {LINIE1, LINIE2, LINIE3, LINIE4, LINIE5, LINIE6, LINIE7, LINIE8}, 8);
unsigned int senzori[8];

void setMotors(int a, int b)
{
	/*
	 * TODO: implementati controlul motoarelor 
	 * a = valoarea pentru motorul stang
	 * b = valoarea pentru motorul drept
	 * Daca primeste valoare negativa, motorul se invarte inapoi.
	 * Pentru a roti motorul intr-o directie, setati unul din pini pe LOW si pe celalalt scrieti
	 * valoarea PWM. Aveti grija la semn, analogWrite primeste o valoare pozitiva (0 - 255).
	 */

}

void printLine()
{
	/*
	 * TODO: Cititi senzorii si trimiteti valorile citite prin interfata seriala.
	 * Pentru citire folositi qtr.read(senzori). Functia va citi senzorii care au fost initializati
	 * la declararea lui qtr si va pune valorile in vectorul senzori.
	 */

}

long getProportional()
{
	long proportional;
	/*
	 * TODO: Functie ce va returna termenul proportional. 
	 * 
	 * Folositi functia qtr.readLine(senzori).
	 * Aceasta copiaza valorile citite in vectorul senzori si returneaza un int intre 0 si 7000,
	 * 0 insemnand ca linia este sub senzorul 1 si 7000 insemnand ca linia este sub senzorul 8.
	 * 
	 * Termenul proportional este reprezentat de devierea de la conditia dorita. Se doreste ca
	 * linia sa se afle pe centru, deci functia va returna o valoare proportionala cu devierea
	 * liniei de la centru. Aceasta va fi negativa daca se afla in stanga si pozitiva daca se 
	 * afla in dreapta.
	 */
	
	
	return proportional;
}

double computePID()
{
	double proportional;
	double derivative;
	/*
	 * Aplicati algoritmul PID 
	 * integral este o variabila globala definita mai sus.
	 * Folositi last_p pentru a calcula termenul derivat.
	 */
	 
	 
	 
	return KP * proportional + KI * integral + KD * derivative;
}

void setup()
{
	Serial.begin(9600);

	pinMode(MOTOR1A, OUTPUT);
	pinMode(MOTOR1B, OUTPUT);
	pinMode(MOTOR2A, OUTPUT);
	pinMode(MOTOR2B, OUTPUT);
	pinMode(13, OUTPUT); //pinul cu led

	digitalWrite(13, HIGH);
	for (int i = 0; i < 125; i++)  { //calibrare senzori
		 //semnalare calibrare prin led-ul legat la pinul 13
		qtr.calibrate();
		delay(20);
		
	}
	digitalWrite(13, LOW);
}


void loop()
{

	setMotors(0,0);
	
	for(int i = 0 ; i < 20 ; i++) {
		printLine();
		delay(50);
	}
	
	setMotors(40, 0);
	delay(500);
	setMotors(0, 40);
	delay(500);
	setMotors(-40, 0);
	delay(500);
	setMotors(0, -40);
	delay(500);
	

	/*
	float pid = computePID();
	if(pid > 0) {
		int a = constrain(SPEED + pid, 0, 255);
		int b = constrain(SPEED - pid, 0, 255);
		setMotors(a, b);
	} else 

	if(pid < 0) {
		int a = constrain(SPEED + pid, 0, 255);
		int b = constrain(SPEED - pid, 0, 255);
		setMotors(a, b);
	} else {
		setMotors(SPEED, SPEED);
	}
	*/

}
