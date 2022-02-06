#include "material.h"

Material::Material(double _dielectricConst)
{
    DIELECTRIC_CONST = _dielectricConst;

}

Material::~Material(){

}

double Material::getDielectricConst(){
    return DIELECTRIC_CONST;
}

void Material::setDielectricConst(double dieConst){
    DIELECTRIC_CONST = dieConst;
}
