//
// Created by lauba on 07/10/22.
//

#ifndef ROBOTOTTO_ROBOTOTTO_H
#define ROBOTOTTO_ROBOTOTTO_H

#include "../lib/Servo/Servo.h"

#define posInicial 90


class RobotOtto {

public:
    RobotOtto();
    void moverPieIzquierdo(int);
    void moverPieDerecho(int);
    void moverPienaIzq(int);
    void moverPienaDer(int);

    virtual ~RobotOtto();

private: Servo piernaIzq;
         Servo piernaDer;
         Servo pieIzq;
         Servo pieDer;

};


#endif //ROBOTOTTO_ROBOTOTTO_H
