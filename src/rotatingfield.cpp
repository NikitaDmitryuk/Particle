#include "rotatingfield.h"

RotatingField::RotatingField(Vector3d _tension)
{
    tension = _tension;
    angleFi = Maths::computeFi(_tension);
    angleTetha = Maths::computeTetha(_tension);
}

void RotatingField::setTension(Vector3d _tension){
    tension = _tension;
}

Vector3d RotatingField::getTension(){
    return tension;
}

void RotatingField::setAngleFi(double _fi){
    angleFi = _fi;
    double r = tension.norm();

    tension[0] = r * sin(angleTetha) * cos(angleFi);
    tension[1] = r * sin(angleTetha) * sin(angleFi);
}

double RotatingField::getAngleFi(){
    return angleFi;
}
