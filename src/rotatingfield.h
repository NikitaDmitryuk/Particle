#ifndef ROTATINGFIELD_H
#define ROTATINGFIELD_H
#include "field.h"
#include <cmath>
#include "maths.h"


class RotatingField : public Field
{
public:
    RotatingField(Vector3d _tension);
    void setTension(Vector3d _tension);
    Vector3d getTension();
    void setAngleFi(double _fi);
    double getAngleFi();

private:
    double angleFi;
    double angleTetha;
};

#endif // ROTATINGFIELD_H
