//
// Created by lauba on 07/10/22.
//

#ifndef ROBOTOTTO_TIPOMOVIMIENTO_H
#define ROBOTOTTO_TIPOMOVIMIENTO_H


#include "RobotOtto.h"

class TipoMovimiento {

protected:
   RobotOtto * otto;

public:
    TipoMovimiento(RobotOtto otto);


    virtual void ejecutar();

    virtual ~TipoMovimiento();

};


#endif //ROBOTOTTO_TIPOMOVIMIENTO_H
