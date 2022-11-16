#include <AccelStepper.h>
#define motorInterfaceType 1
//Grupo 16 

const int dirPin = 10;
const int stepPin = 13;
const int pulsador=12;
const int led=11;
const int ledRojo=7;

int estadoSistema = LOW;   
int buttonState;            
int lastButtonState = LOW;  
int reading;
int contador=-2;

unsigned long lastDebounceTime = 0;                                 
unsigned long debounceDelay = 50;    // tiempo para el antirebote

AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);


void setup() {
   //Se define los pines de entrada y salida
   pinMode(pulsador, INPUT_PULLUP); 
   pinMode(led, OUTPUT);
   pinMode(ledRojo, OUTPUT);
   digitalWrite(led, estadoSistema);

  Serial.begin(9600);
	myStepper.setMaxSpeed(1000);
	myStepper.setAcceleration(50);
	myStepper.setSpeed(200);
	myStepper.moveTo(200);

}

void loop() {
   bool estadoPulsador = debounceReadButton();
   if (estadoPulsador) { //funciones cuando el sistema este encendido
      digitalWrite(led, estadoSistema);
      myStepper.run();
      contador++;
      delay(2000);//en este delay se añade o quita tiempo para que el motor gire más despacio o más rapido
      
      if (myStepper.distanceToGo() == 0) {
        digitalWrite(led, LOW);
        digitalWrite(ledRojo, HIGH);
        delay(100);
        digitalWrite(ledRojo, LOW);
        contador=0;
        
      }
   } 
    else{//funciones cuando el sistema se encuentre apagado
      digitalWrite(led, estadoSistema);
      digitalWrite(ledRojo, LOW);
      
    }
    Serial.println(contador);
 
   lastButtonState = reading;
  }



int debounceReadButton(){ 
  reading = digitalRead(pulsador);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
// Solo si el pulsador a estado más tiempo que el de anti-rebote programado, cambiaremos el valor de la variable buttonState
  if ((millis() - lastDebounceTime) > debounceDelay) {
    
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        estadoSistema = !estadoSistema;
      }
    
  }
  return estadoSistema;

}
}