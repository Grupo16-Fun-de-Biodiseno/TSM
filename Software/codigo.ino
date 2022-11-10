#include <AccelStepper.h>
#define motorInterfaceType 1
//Grupo 16 

const int dirPin = 10;
const int stepPin = 13;
const int pulsador=12;
const int led=11;
const int ledRojo=7;

int estado;

AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);


void setup() {
   //Se define los pines de entrada y salida
   pinMode(pulsador, INPUT_PULLUP); 
   pinMode(led, OUTPUT);
   pinMode(ledRojo, OUTPUT);

  Serial.begin(9600);
	myStepper.setMaxSpeed(1000);
	myStepper.setAcceleration(50);
	myStepper.setSpeed(200);
	myStepper.moveTo(200);

}

void loop() {
   estado = digitalRead(pulsador);
   Serial.println(estado); 
   if(estado==LOW){
         	if (myStepper.distanceToGo() == 0) 
		myStepper.moveTo(-myStepper.currentPosition());

	// Move the motor one step
	myStepper.run();
   }
  
  }


