#ifndef MATERIAL_H
#define MATERIAL_H

#include "print.h"

class Material
{
public:
    Material(double _dielectricConst);
    ~Material();
    double getDielectricConst();
    void setDielectricConst(double dieConst);
private:
    double DIELECTRIC_CONST;
};

#endif // MATERIAL_H
