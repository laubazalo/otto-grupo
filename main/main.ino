#include <Arduino.h>
#include "OttoUnit.h"
#include <SoftwareSerial.h>
#include "Property.h"
#include "Servo.h"



OttoUnit ottoUnit;
SoftwareSerial miBT(10,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ottoUnit.init();
  miBT.begin(9600);
}
int comando=0;
void loop() {
    ottoUnit.returnPosInit();
    if(miBT.available()){
     comando=miBT.read();
     ottoUnit.executeRemote(30, comando); // camina adelante
    }
}
