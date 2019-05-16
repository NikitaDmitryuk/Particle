#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;

class Shape
{
public:
    Shape(double _diamete);
    ~Shape();
    double getDiameter();
    void setDiameter(double d);

private:
    double diameter;
};

#endif // SHAPE_H
