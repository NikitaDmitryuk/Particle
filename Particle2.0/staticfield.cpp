#include "staticfield.h"

StaticField::StaticField(Vector3d _tension)
{
    tension = _tension;
}

StaticField::~StaticField()
{

}

Vector3d StaticField::getTension(){
    return tension;
}

void StaticField::setTension(Vector3d t){
    tension = t;
}

void StaticField::setAngleFi(double _fi){
    return;
}

double StaticField::getAngleFi(){
    return 0;
}
