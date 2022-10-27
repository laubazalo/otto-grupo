#include <Arduino.h>
#include <SoftwareSerial.h>
#include "TipoMovimiento.h"
#include "FactoryBuilder.h"

SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth


void (*vector[20])(void)={
&FactoryBuilder::caminarAdelante
};


void setup(){
   
   // BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
    Serial.begin(9600);   // Inicializamos  el puerto serie
}

void loop() {

    vector[0]();
    delay(1000);

}