#include "shape.h"

Shape::Shape(double _diameter)
{
    diameter = _diameter;

}

Shape::~Shape(){

}

double Shape::getDiameter(){
    return diameter;
}

void Shape::setDiameter(double d){
    diameter = d;
}
