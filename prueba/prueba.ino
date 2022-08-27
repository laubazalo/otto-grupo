#include <SoftwareSerial.h>

//d0: RX
//d1: TX

SoftwareSerial miBT(10, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  miBT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (miBT.available()) {   // if HM10 sends something then read

    Serial.println(miBT.readString());

  }
  
}
