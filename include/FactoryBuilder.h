//
// Created by lauba on 06/10/22.
//

#ifndef ROBOTOTTO_FACTORYBUILDER_H
#define ROBOTOTTO_FACTORYBUILDER_H


#include "RobotOtto.h"
#include "TipoMovimiento.h"

class FactoryBuilder {
private:
     RobotOtto * robotOtto = new RobotOtto();

public:
    static void caminarAdelante();
    static void girarDerecha();
    static void girarIzquierda();
    static void bend();
    static void caminaLunar();
    static void crusaito();
    static void aleteo();
    static void swing();
    static void nervioso();
    static void subirBajar();
    static void feliz();
    static void superFeliz();
    static void triste();
    static void victoria();
    static void enojado();
    static void dormido();
    static void amor();
    static void confundido();
    static void fart();
    static void caida();
};


#endif //ROBOTOTTO_FACTORYBUILDER_H
