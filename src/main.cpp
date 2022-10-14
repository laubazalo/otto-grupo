#include <Arduino.h>
#include <SoftwareSerial.h>
#include "TipoMovimiento.h"
#include "FactoryBuilder.h"

SoftwareSerial BT(10,11);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth


TipoMovimiento (*vector[20])(void)={
&FactoryBuilder::caminarAdelante
};


void setup(){
    FactoryBuilder::initFactory(); // Inicializa el factory (crea el obj robotOtto)
    BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
    Serial.begin(9600);   // Inicializamos  el puerto serie
}

void loop() {

    vector[0]().ejecutar();
    delay(1000);

    /*
    if (BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
    {
        Serial.write(BT.read());
    }

    if (Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
    {
        BT.write(Serial.read());
    }
    */

}