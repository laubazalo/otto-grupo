#pragma once
#include <Arduino.h>
#include <Servo.h>
#include <EnumStateBody.h>
#include <Property.h>

//#include <OttoTransistor.h>

class Otto{
	public:
		void init();
		static void returnPosInit();
		
	private:
		void initServomotores();
		void initPosition();
		
	protected:
		static uint8_t extremities[4];
		static uint8_t extremitiesPosInit[4];
		static Servo legRight_servo;
		static Servo legLeft_servo;
		static Servo footRight_servo;
		static Servo footLeft_servo;
		
		static void firstStep(uint8_t movDir, uint8_t movGrados);
		static void moveLegs(uint8_t movDir, uint8_t movGrados);
		static void moveFoots(uint8_t movDir, uint8_t movGrados);
};