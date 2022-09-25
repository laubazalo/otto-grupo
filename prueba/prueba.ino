#include <SoftwareSerial.h>
#include <Servo.h>
#include "CaminarAdelante.h"

//d0: RX
//d1: TX
//pie1: pin2
//pierna Izq inicial: 90
Servo pie1;
Servo pie2; 
SoftwareSerial miBT(10, 11);

class MiClase
{
  public: static void mover(){
      Serial.println("Llega a clase");
    }
}; 
void (*funcptr)(void) = NULL;
int (*vector[20])(void) = {&Movimientos::caminarAdelante, &Movimientos::caminarAtras,
                          &Movimientos::caminarAdelante1, &Movimientos::caminarAtras1,
                          &Movimientos::caminarAdelante2, &Movimientos::caminarAtras2,
                          &Movimientos::caminarAdelante3, &Movimientos::caminarAtras3,
                          &Movimientos::caminarAdelante4, &Movimientos::caminarAtras4,
                          &Movimientos::caminarAdelante5, &Movimientos::caminarAtras5,
                          &Movimientos::caminarAdelante6, &Movimientos::caminarAtras6,
                          &Movimientos::caminarAdelante7, &Movimientos::caminarAtras7,
                          &Movimientos::caminarAdelante8, &Movimientos::caminarAtras8,
                          &Movimientos::caminarAdelante9, &Movimientos::caminarAtras9}; 

int PINPIE1 = 2;
int PINPIE2 = 3; 
int PULSOMIN = 1300; //izquierdo
int PULSOMAX = 2500; //izquierdo
uint8_t comando = 90;


void setup() {
  // put your setup code here, to run once:
  pie1.attach(PINPIE1);
  pie2.attach(PINPIE2);
  Serial.begin(9600);
  miBT.begin(9600);
  Serial.print("Listo");
}

void loop() {
  // put your main code here, to run repeatedly:
  int value;;

  if (miBT.available()) {   // if HM10 sends something then read
    delay(1500);
    comando = miBT.read();
    Serial.println(comando);
    value = vector[comando]();
    //vector[comando].mover();
    Serial.println(value);
    
  }
  
  /*
  pie1.write(comando);
  delay(1000);
  comando = 90;
  */
}
