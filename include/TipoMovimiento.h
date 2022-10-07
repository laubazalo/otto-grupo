//
// Created by lauba on 07/10/22.
//

#ifndef ROBOTOTTO_TIPOMOVIMIENTO_H
#define ROBOTOTTO_TIPOMOVIMIENTO_H


class TipoMovimiento {
    RobotOtto otto;

public:
    TipoMovimiento();

    TipoMovimiento(const RobotOtto & otto);


    virtual void ejecutar();

    virtual ~TipoMovimiento();

};


#endif //ROBOTOTTO_TIPOMOVIMIENTO_H
