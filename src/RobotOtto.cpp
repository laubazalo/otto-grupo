//
// Created by lauba on 07/10/22.
//

#include "RobotOtto.h"

RobotOtto::RobotOtto() {
    this->pieDer.attach(2);
    this->pieIzq.attach(3);
    this->piernaDer.attach(4);
    this->piernaIzq.attach(5);
}

void RobotOtto::moverPienaDer(int value) {
    this->piernaDer.write(value);

}

void RobotOtto::moverPienaIzq(int value) {
    this->piernaDer.write(value);
}

void RobotOtto::moverPieDerecho(int value) {
    this->piernaDer.write(value);

}

void RobotOtto::moverPieIzquierdo(int value) {
    this->piernaDer.write(value);
}

RobotOtto::~RobotOtto() {
    //Implementar destructor
}


