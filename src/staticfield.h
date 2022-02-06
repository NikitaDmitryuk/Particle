#ifndef STATICFIELD_H
#define STATICFIELD_H
#include "field.h"
#include <eigen3/Eigen/Eigen>

using namespace Eigen;

class StaticField : public Field
{
public:
    StaticField(Vector3d _tension);
    ~StaticField();

    Vector3d getTension();
    void setTension(Vector3d t);
    void setAngleFi(double _fi);
    double getAngleFi();
};

#endif // STATICFIELD_H
