#include <SoftwareSerial.h>
#include <Servo.h>

//d0: RX
//d1: TX
//pie1: pin2

Servo pie1; 
SoftwareSerial miBT(10, 11);

int PINPIE1 = 2; 
int PULSOMIN = 1300;
int PULSOMAX = 2500;
uint8_t comando = 90;

void setup() {
 // put your setup code here, to run once:
 pie1.attach(PINPIE1);
 Serial.begin(9600);
 miBT.begin(9600);
}
void loop() {
 // put your main code here, to run repeatedly:

 if (miBT.available()) {   // if HM10 sends something then read

   comando = miBT.read();
   Serial.println(comando);
 }

 pie1.write(comando);
 delay(1000);
 comando = 90;
}
