//
// Created by lauba on 07/10/22.
//
#include <HardwareSerial.h>
#include "CaminarAdelante.h"

void CaminarAdelante::ejecutar() {
    //Pie izq anti horario
    //Pierna izq
    //Pie a 0
    //Pierna a 0
    //Volver a pos normal
    //El otro lado seria lo opuesto
    Serial.println("ANDA");
}

CaminarAdelante::CaminarAdelante(RobotOtto otto): TipoMovimiento(otto) {

}


