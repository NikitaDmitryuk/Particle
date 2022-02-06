#ifndef DIPOLE_H
#define DIPOLE_H

#include <eigen3/Eigen/Eigen>
#include "print.h"

using namespace Eigen;

class Dipole
{
public:
    Dipole(Vector3d _dipolVector);
    ~Dipole();
    Vector3d getApplicationPoint();
    void setApplicationPoint(Vector3d _applicationPoint);
    Vector3d getDipoleVector();
    void setDipoleVector(Vector3d _dipilepoint);

private:
    Vector3d applicationPoint;
    Vector3d dipolVector;
};

#endif // DIPOLE_H
