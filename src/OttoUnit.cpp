#include <OttoUnit.h>
#include <Property.h>
#include <Servo.h>
#include <EnumStateBody.h>

struct position_t{
	//No incluye al caracter 0
	uint8_t footLeft; //Pie izquierdo
	uint8_t footRight; //Pie derecho
	uint8_t legLeft; //Pierna izquierda
	uint8_t legRight; //pierna derecha
} __attribute__((packed));

void OttoUnit::swing(uint8_t velocidad){
	Serial.println("swing");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		footLeft_servo.write(pos->footLeft);
		delay(velocidad);
	}
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft - 1;
		pos->footRight = pos->footRight - 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight + 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft - 1;
		footLeft_servo.write(pos->footLeft);
		delay(velocidad);
	}
	Otto::returnPosInit();
};

void OttoUnit::walkFordward(uint8_t velocidad){
	Serial.println("walkFordward");
	Otto::firstStep(1, velocidad); // 0 ADELANTE - 1 ATRAS
	Otto::moveLegs(0, velocidad);
	Otto::moveFoots(0, velocidad);
	Otto::moveLegs(1, velocidad);
	Otto::moveFoots(1, velocidad);
	Otto::returnPosInit();
	
};

void OttoUnit::walkBackground(uint8_t velocidad){
	Serial.println("walkBackground");
	Otto::firstStep(0, velocidad); // 0 ADELANTE - 1 ATRAS
	Otto::moveFoots(1, velocidad);
	Otto::moveLegs(1, velocidad);
	Otto::moveFoots(0, velocidad);
	Otto::moveLegs(0, velocidad);
	Otto::returnPosInit();
};

void OttoUnit::turnLeft(uint8_t velocidad){
	Serial.println("turnLeft");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	//Primer movimiento
	for(uint8_t i=0; i<30; i++){
		pos->footRight = pos->footRight - 1;
		pos->legRight = pos->legRight + 1;
		legRight_servo.write(pos->legRight);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight + 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footRight = pos->footRight - 1;
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->legRight = pos->legRight + 2;
		legRight_servo.write(pos->legRight);
		delay(velocidad);
	}
};

void OttoUnit::turnRigth(uint8_t velocidad){
	Serial.println("turnRigth");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	//Primer movimiento
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->legLeft = pos->legLeft - 1;
		legLeft_servo.write(pos->legLeft);
		footLeft_servo.write(pos->footLeft);
		delay(15);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft - 1;
		pos->footRight = pos->footRight - 1;
		footRight_servo.write(pos->footRight);
		footLeft_servo.write(pos->footLeft);
		delay(15);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->legLeft = pos->legLeft + 2;
		pos->footRight = pos->footRight + 1;
		legLeft_servo.write(pos->legLeft);
		footRight_servo.write(pos->footRight);
		delay(15);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		footLeft_servo.write(pos->footLeft);
		delay(15);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->legLeft = pos->legLeft - 2;
		legLeft_servo.write(pos->legLeft);
		delay(15);
	}
};

void OttoUnit::bend(uint8_t velocidad, uint8_t sentido){
	Serial.println("bend");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	if (sentido){
		for(uint8_t i=0; i<50; i++){
			pos->footRight = pos->footRight - 1;
			footRight_servo.write(pos->footRight);
			delay(velocidad);
		}
		
		for(uint8_t i=0; i<50; i++){
			pos->footRight = pos->footRight + 1;
			footRight_servo.write(pos->footRight);
			if(i>=40){
				pos->footLeft = pos->footLeft - 1;
				footLeft_servo.write(pos->footLeft);
			}
			delay(velocidad);
		}
	}else{
		for(uint8_t i=0; i<50; i++){
			pos->footLeft = pos->footLeft + 1;
			footLeft_servo.write(pos->footLeft);
			delay(velocidad);
		}
		for(uint8_t i=0; i<50; i++){
			pos->footLeft = pos->footLeft - 1;
			footLeft_servo.write(pos->footLeft);
			if(i>=40){
				pos->footRight = pos->footRight + 1;
				footRight_servo.write(pos->footRight);
			}
			delay(velocidad);
		}
	}
};

void OttoUnit::shakeLeg(uint8_t velocidad){
	Serial.println("shakeLeg");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		footLeft_servo.write(pos->footLeft);
		if (i==15){
			pos->footRight = pos->footRight - 1;
			footRight_servo.write(pos->footRight);
		}
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft - 1;
		footLeft_servo.write(pos->footLeft);
		delay(10);
	}
	
	for(uint8_t i=0; i<30; i++){
		if (i>15){
			pos->footLeft = pos->footLeft - 1;
		}else{
			pos->footLeft = pos->footLeft + 1;
		}
			footLeft_servo.write(pos->footLeft);
			delay(10);
	}
};

void OttoUnit::moonWalker(uint8_t velocidad){
	Serial.println("moonWalker");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<30; i++){
		pos->footRight = pos->footRight - 1;
		footRight_servo.write(pos->footRight);
		delay(10);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		footLeft_servo.write(pos->footLeft);
		delay(10);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footRight = pos->footRight + 1;
		footRight_servo.write(pos->footRight);
		delay(10);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft - 1;
		footLeft_servo.write(pos->footLeft);
		delay(10);
	}
};

void OttoUnit::crusaito(uint8_t velocidad){
	Serial.println("crusaito");
	walkFordward(velocidad);
	moonWalker(velocidad);
};

void OttoUnit::flapping(uint8_t velocidad){
	Serial.println("flapping");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<60; i++){
		if (i<30){
			pos->footLeft = pos->footLeft + 1;
			pos->footRight = pos->footRight - 1;
		}else{
			pos->footLeft = pos->footLeft - 1;
			pos->footRight = pos->footRight + 1;
		}
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<60; i++){
		if (i<30){
			pos->footLeft = pos->footLeft + 1;
			pos->footRight = pos->footRight - 1;
			pos->legRight = pos->legRight - 1;
			pos->legLeft = pos->legLeft + 1;
		}else{
			pos->footLeft = pos->footLeft - 1;
			pos->footRight = pos->footRight + 1;
			pos->legRight = pos->legRight + 1;
			pos->legLeft = pos->legLeft - 1;
		}
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		legLeft_servo.write(pos->legLeft);
		legRight_servo.write(pos->legRight);
		delay(velocidad);
	}
};

void OttoUnit::tiptoeSwing(uint8_t velocidad){
	Serial.println("tiptoeSwing");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<30; i++){
		pos->legLeft = pos->legLeft + 1;
		pos->legRight = pos->legRight - 1;
		legLeft_servo.write(pos->legLeft);
		legRight_servo.write(pos->legRight);
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<60; i++){
		pos->legLeft = pos->legLeft - 1;
		pos->legRight = pos->legRight + 1;
		legLeft_servo.write(pos->legLeft);
		legRight_servo.write(pos->legRight);
		delay(velocidad);
	}
};

void OttoUnit::jitter(uint8_t velocidad){
	Serial.println("jitter");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<60; i++){
		if (i<30){
			pos->footLeft = pos->footLeft + 1;
			pos->footRight = pos->footRight - 1;
		}else{
			pos->footLeft = pos->footLeft - 1;
			pos->footRight = pos->footRight + 1;
		}
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<60; i++){
		if (i<30){
			pos->footLeft = pos->footLeft + 1;
			pos->footRight = pos->footRight - 1;
			pos->legRight = pos->legRight + 1;
			pos->legLeft = pos->legLeft - 1;
		}else{
			pos->footLeft = pos->footLeft - 1;
			pos->footRight = pos->footRight + 1;
			pos->legRight = pos->legRight - 1;
			pos->legLeft = pos->legLeft + 1;
		}
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		legLeft_servo.write(pos->legLeft);
		legRight_servo.write(pos->legRight);
		delay(velocidad);
	}
};

void OttoUnit::happy(uint8_t velocidad){
	Serial.println("happy");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight - 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	
	//Sube y baja
	for(uint8_t i=0; i<15; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight - 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft - 1;
		pos->footRight = pos->footRight + 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight - 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
};

void OttoUnit::love(uint8_t velocidad){
	Serial.println("love");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<45; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight - 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(velocidad);
	}
	pos->footLeft = POS_INIT;
	pos->footRight = POS_INIT;
	footLeft_servo.write(pos->footLeft);
	footRight_servo.write(pos->footRight);
	delay(velocidad);
};

void OttoUnit::fart(uint8_t velocidad){
	Serial.println("fart");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft + 1;
		footLeft_servo.write(pos->footLeft);
		
		if (i==15){
			pos->footRight = pos->footRight - 1;
			footRight_servo.write(pos->footRight);
		}
		delay(velocidad);
	}
	for(uint8_t i=0; i<30; i++){
		pos->footLeft = pos->footLeft - 1;
		footLeft_servo.write(pos->footLeft);
		delay(velocidad);
	}
};

void OttoUnit::end(uint8_t velocidad){
	Serial.println("end");
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<100; i++){
		pos->footLeft = pos->footLeft + 1;
		footLeft_servo.write(pos->footLeft);
		delay(velocidad/2);
	}
	
	for(uint8_t i=0; i<100; i++){
		pos->footRight = pos->footRight + 1;
		footRight_servo.write(pos->footRight);
	}
};

void OttoUnit::sad(uint8_t velocidad){
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	Serial.println("Sad");

	for(uint8_t i=0; i<60;i++){
		pos->footLeft = pos->footLeft -1;
		pos->footRight = pos->footRight+1;
		footLeft_servo.write(pos->footLeft);
		delay(15);
		footRight_servo.write(pos->footRight);
	}
	delay(500);
}

void OttoUnit::angry(uint8_t velocidad){
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	Serial.println("Angry");

	for(uint8_t i=0; i<60;i++){
		pos->legLeft = pos->legLeft + 1;
		pos->legRight = pos->legRight+1;
		legLeft_servo.write(pos->legLeft);
		delay(15);
		legRight_servo.write(pos->legRight);
	}
	delay(500);
	returnPosInit();
}
void OttoUnit::sleeping(uint8_t velocidad){
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	Serial.println("Sleeping");

	for(uint8_t i=0; i<20;i++){
		pos->footRight = pos->footRight+1;
		footRight_servo.write(pos->footRight);
		delay(15);
	}
	delay(500);
	returnPosInit();
}

void OttoUnit::superHappy(uint8_t velocidad){
	Serial.println("Super Happy");

	position_t *pos = reinterpret_cast<position_t *>(extremities);
	
	for(uint8_t i=0; i<50; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight - 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(10);
	}
	
	//Sube y baja
	for(uint8_t i=0; i<15; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight - 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(5);
	}
	
	for(uint8_t i=0; i<50; i++){
		pos->footLeft = pos->footLeft - 1;
		pos->footRight = pos->footRight + 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(10);
	}
	
	for(uint8_t i=0; i<50; i++){
		pos->footLeft = pos->footLeft + 1;
		pos->footRight = pos->footRight - 1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(10);
	}
	returnPosInit();

}

void OttoUnit::upDown(uint8_t velocidad ){
	position_t *pos = reinterpret_cast<position_t *>(extremities);
	Serial.println("Up down");
	for(uint8_t i =0; i <60 ; i++){
		pos-> footLeft = pos->footLeft +1;
		pos-> footRight = pos->footRight -1;
		footLeft_servo.write(pos->footLeft);
		footRight_servo.write(pos->footRight);
		delay(10);
	}
}



void OttoUnit::executeRemote(uint8_t velocidad, uint8_t funcionalidad){
	functionOtto[funcionalidad](velocidad);
};


