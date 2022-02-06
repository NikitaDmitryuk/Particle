#ifndef FIELD_H
#define FIELD_H

#include <eigen3/Eigen/Eigen>
#include "print.h"

using namespace Eigen;

class Field
{
public:
    Field();
    virtual ~Field();
    virtual void setTension(Vector3d)=0;
    virtual Vector3d getTension()=0;
    virtual void setAngleFi(double _fi)=0;
    virtual double getAngleFi()=0;

protected:
    Vector3d tension;
};

#endif // FIELD_H
