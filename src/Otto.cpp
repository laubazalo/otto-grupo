#include <Property.h>
#include <Otto.h>
#include <EnumStateBody.h>

uint8_t Otto::extremities[4];
uint8_t Otto::extremitiesPosInit[4];


Servo Otto::legRight_servo;
Servo Otto::legLeft_servo;
Servo Otto::footRight_servo;
Servo Otto::footLeft_servo;

struct position_t{
	//No incluye al caracter 0
	uint8_t footLeft; //Pie izquierdo
	uint8_t footRight; //Pie derecho
	uint8_t legLeft; //Pierna izquierda
	uint8_t legRight; //pierna derecha
} __attribute__((packed));

void Otto::init(){
	//Configuracion de transistores para alimentación de motores
	initServomotores();
	initPosition();
};

void Otto::initServomotores(){
	//Inicio de los servomotores
	footLeft_servo.attach(FOOT_LEFT_SERVO);
	footRight_servo.attach(FOOT_RIGTH_SERVO);
	legRight_servo.attach(LEG_RIGTH_SERVO);
	legLeft_servo.attach(LEG_LEFT_SERVO);
}

void Otto::initPosition(){
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	position_t *posInit = reinterpret_cast<position_t *>(extremitiesPosInit);
	
	pos->footLeft = POS_INIT - 8;
	pos->footRight = POS_INIT - 7;
	pos->legLeft = POS_INIT - 8;
	pos->legRight = POS_INIT + 5;
	
	posInit->footLeft = POS_INIT - 8;
	posInit->footRight = POS_INIT - 7;
	posInit->legLeft = POS_INIT - 8;
	posInit->legRight = POS_INIT + 5;
	
	footLeft_servo.write(pos->footLeft);
	footRight_servo.write(pos->footRight);
	legLeft_servo.write(pos->legLeft);
	legRight_servo.write(pos->legRight);
}
	//movDir suma 1 mandando 0
	void Otto::firstStep(uint8_t movDir, uint8_t movGrados){
		position_t *pos = reinterpret_cast<position_t *>(extremities);
		
		//Primer paso - CAMINAR ADELANTE
		for (uint8_t i=0; i<movGrados; i++){
			if(movDir){ 
				pos->legRight = pos->legRight + 1;
				pos->footLeft = pos->footLeft + 1;
				pos->legLeft = pos->legLeft + 1;
			}else{ //Primer paso CAMINAR ATRAS
				pos->legRight = pos->legRight - 1;
				pos->legRight = pos->legRight - 1;
				pos->legLeft = pos->legLeft - 1;
			}
			
			legRight_servo.write(pos->legRight);
			footLeft_servo.write(pos->footLeft);
			legLeft_servo.write(pos->legLeft);
			delay(10);
		}
	};
	
	void Otto::moveLegs(uint8_t movDir, uint8_t movGrados){
		position_t *pos = reinterpret_cast<position_t *>(extremities);
		
		for (uint8_t i=0; i<movGrados; i++){
			if (movDir){ //1
				pos->legRight = pos->legRight + 1;
				pos->legLeft = pos->legLeft + 1;
			}else{ //0
				pos->legRight = pos->legRight - 1;
				pos->legLeft = pos->legLeft - 1;
			}		
			legRight_servo.write(pos->legRight);
			legLeft_servo.write(pos->legLeft);
			delay(10);
		}
	};
	
	void Otto::moveFoots(uint8_t movDir, uint8_t movGrados){
		position_t *pos = reinterpret_cast<position_t *>(extremities);
		for (uint8_t i=0; i<movGrados; i++){
			if(movDir){
				pos->footRight = pos->footRight + 1;
				pos->footLeft = pos->footLeft + 1;
			}else{
				pos->footRight = pos->footRight - 1;
				pos->footLeft = pos->footLeft - 1;
			}
			footRight_servo.write(pos->footRight);
			footLeft_servo.write(pos->footLeft);
			delay(10);
		}
	};
	
	void Otto::returnPosInit(){
		for (uint8_t i=0; i<4; i++){
			while(extremities[i] != extremitiesPosInit[i]){
				if (extremities[i] < extremitiesPosInit[i]){
					extremities[i] = extremities[i] + 1;
				}else{
					extremities[i] = extremities[i] - 1;
				}
				switch(i){
					case 0:
						footLeft_servo.write(extremities[i]);
						break;
					case 1:
						footRight_servo.write(extremities[i]);
						break;
					case 2:
						legLeft_servo.write(extremities[i]);
						break;
					case 3:
						legLeft_servo.write(extremities[i]);
						break;
					default:
						Serial.println("No se está seleccionando el moto correcto");
						break;
				}
				delay(15);
			}
		}
	};
	
