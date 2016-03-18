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
const float KP = 1.0;
const float KD = 0.0;
const float KI = 0.0;

int last_p = 0;
int integral = 0;
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
	 * Pentru citire folositi qtr.read(sensors). Functia va citi senzorii care au fost initializati
	 * la declararea lui qtr si va pune valorile in vectorul sensors.
	 */

}

long getProportional()
{

	return 0;
}

double computePID()
{

	return 0;
}

void setup()
{
	Serial.begin(9600);

	pinMode(MOTOR1A, OUTPUT);
	pinMode(MOTOR1B, OUTPUT);
	pinMode(MOTOR2A, OUTPUT);
	pinMode(MOTOR2B, OUTPUT);

	delay(3000);
}


void loop()
{


	



	

	/*
	int pid = computePID();
	if(pid > 0) {
		int a = constrain(0, 255, SPEED + pid);
		int b = constrain(0, 255, SPEED - pid);
		setMotors(a, b);
	} else 

	if(pid < 0) {
		int a = constrain(0, 255, SPEED - pid);
		int b = constrain(0, 255, SPEED + pid);
		setMotors(a, b);
	} else {
		setMotors(SPEED, SPEED);
	}
	*/

}
