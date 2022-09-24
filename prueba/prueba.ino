#include <SoftwareSerial.h>
#include <Servo.h>
#include "CaminarAdelante.h"

//d0: RX
//d1: TX
//pie1: pin2
//pierna Izq inicial: 90
Servo pie1; 
SoftwareSerial miBT(10, 11);

class MiClase
{
  public: static void mover(){
      Serial.println("Llega a clase");
    }
}; 
void (*funcptr)(void) = NULL;
int vector[2] = {&Movimientos::caminarAdelante, &Movimientos::caminarAtras}; 

int value;
int PINPIE1 = 2; 
int PULSOMIN = 1300; //izquierdo
int PULSOMAX = 2500; //izquierdo
uint8_t comando = 90;


void setup() {
  // put your setup code here, to run once:
  pie1.attach(PINPIE1);
  Serial.begin(9600);
  miBT.begin(9600);
  Serial.print("Listo");
}

void loop() {
  // put your main code here, to run repeatedly:
  int value;
  value = *funcptr[1]();
  if (miBT.available()) {   // if HM10 sends something then read
    comando = miBT.read();
    Serial.println(comando);
    //vector[comando].mover();
    Serial.println(value);
    
  }
  /*
  pie1.write(comando);
  delay(1000);
  comando = 90;
  */
}
