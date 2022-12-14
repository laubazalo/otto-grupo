#ifndef PROPERTY_H
#define PROPERTY_H

#include <Arduino.h>
/*Variables asignadas a cada servo. Estas son para un Arduino MEGA
  Se necesitan que todas sean PWM, caso contrario, se podría pensar en simularlo
  - Tension = 3.3V
  - Corriente = 12mA
*/

static const uint8_t LEG_RIGTH_SERVO = 5;
static const uint8_t LEG_LEFT_SERVO = 4;
static const uint8_t FOOT_LEFT_SERVO = 2;
static const uint8_t FOOT_RIGTH_SERVO = 3;


//Pines de los analógicos (usados como digital) para alimentar a los transistores y as+i darle energía a los pies y piernas

static const uint8_t FOOT_RIGTH_TRANSISTOR = A4;
static const uint8_t FOOT_LEFT_TRANSISTOR = A5;
static const uint8_t LEG_RIGTH_TRANSISTOR = A0;
static const uint8_t LEG_LEFT_TRANSISTOR = A2;


/*Posición inicial de cada servo
  La calibración es para ver si todo se mueve y funciona correctamente, se entiende que se respeta un estructura
  definida por el que lo construye
  - MÁXIMO ángulo de giro en todo el código 
  - MÍNIMO ángulo de giro en todo el código
*/

static const uint8_t POS_INIT = 90;
static const uint8_t POS_INIT_MAX = 120;
static const uint8_t POS_INIT_MIN = 60;

#endif