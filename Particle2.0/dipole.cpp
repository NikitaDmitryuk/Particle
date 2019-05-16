#include "dipole.h"

Dipole::Dipole(Vector3d _dipolVector)
{
    dipolVector = _dipolVector;

}

Dipole::~Dipole(){

}

Vector3d Dipole::getApplicationPoint(){
    return applicationPoint;
}

void Dipole::setApplicationPoint(Vector3d point){
    applicationPoint = point;
}

Vector3d Dipole::getDipoleVector(){
    return dipolVector;
}

void Dipole::setDipoleVector(Vector3d _dipilepoint){
    dipolVector = _dipilepoint;
}
