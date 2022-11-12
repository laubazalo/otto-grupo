#pragma once

#include <Arduino.h>
#include <Otto.h>

class OttoUnit : public Otto{
	public:
		void (*functionOtto[20])(uint8_t) = {
			walkFordward, walkBackground, turnLeft,
			turnRigth, swing, shakeLeg, moonWalker,
			crusaito, flapping,
			tiptoeSwing, jitter, happy, love,
			fart,upDown,sad,angry,sleeping,superHappy,end
			};
		
		void executeRemote(uint8_t velocidad, uint8_t funcionalidad);
		
	private:
		static void swing(uint8_t velocidad);
		static void walkFordward(uint8_t velocidad);
		static void walkBackground(uint8_t velocidad);
		static void turnLeft(uint8_t velocidad);
		static void turnRigth(uint8_t velocidad);
		static void shakeLeg(uint8_t velocidad);
		static void bend(uint8_t velocidad, uint8_t sentido);
		static void moonWalker(uint8_t velocidad);
		static void crusaito(uint8_t velocidad);
		static void flapping(uint8_t velocidad);
		static void tiptoeSwing(uint8_t velocidad);
		static void jitter(uint8_t velocidad);
		static void happy(uint8_t velocidad);
		static void love(uint8_t velocidad);
		static void fart(uint8_t velocidad);
		static void end(uint8_t velocidad);		
		static void sad(uint8_t velocidad);
		static void angry(uint8_t velocidad);
		static void sleeping(uint8_t velocidad);
		static void superHappy(uint8_t velocidad);
		static void upDown(uint8_t velocidad);
};