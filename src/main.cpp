#include <Arduino.h>
#include <OttoUnit.h>

OttoUnit otto;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  otto.executeRemote(2000,0); // velocidad =5 ; walkforward
}

void loop() {
  // put your main code here, to run repeatedly:
}