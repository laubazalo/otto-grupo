//
// Created by lauba on 06/10/22.
//

#ifndef ROBOTOTTO_FACTORYBUILDER_H
#define ROBOTOTTO_FACTORYBUILDER_H


#include "RobotOtto.h"
#include "TipoMovimiento.h"

class FactoryBuilder {
private:
    static RobotOtto * robotOtto;

public:

    static void initFactory();
    static TipoMovimiento caminarAdelante();
    static int girarDerecha();
    static int girarIzquierda();
    static int bend();
    static int caminaLunar();
    static int crusaito();
    static int aleteo();
    static int swing();
    static int nervioso();
    static int subirBajar();
    static int feliz();
    static int superFeliz();
    static int triste();
    static int victoria();
    static int enojado();
    static int dormido();
    static int amor();
    static int confundido();
    static int fart();
    static int caida();
};


#endif //ROBOTOTTO_FACTORYBUILDER_H
