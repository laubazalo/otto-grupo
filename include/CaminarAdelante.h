//
// Created by lauba on 07/10/22.
//

#ifndef ROBOTOTTO_CAMINARADELANTE_H
#define ROBOTOTTO_CAMINARADELANTE_H


#include "TipoMovimiento.h"

class CaminarAdelante : public TipoMovimiento{


public:
     CaminarAdelante(RobotOtto otto);

    void ejecutar();
};


#endif //ROBOTOTTO_CAMINARADELANTE_H
