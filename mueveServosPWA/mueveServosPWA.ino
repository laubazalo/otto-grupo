#include <SoftwareSerial.h>
#include <Servo.h>

//d0: RX
//d1: TX
//pie1: pin2

Servo pie1; 
Servo pie2; 
SoftwareSerial miBT(10, 11);

int PINPIE1 = 2; 
int PINPIE2 = 3; 
int PULSOMIN = 1300;
int PULSOMAX = 2500;
uint8_t comando = 90;

void setup() {
 // put your setup code here, to run once:
 pie2.attach(PINPIE2);
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

 for(int i=90; i<180; i+=10){
    pie1.write(i);
    pie2.write(i);
    delay(50);
    
   }
   pie1.write(90);
   pie2.write(90);
 
 delay(1000);
 comando = 90;
}