#ifndef COMPUTE_H
#define COMPUTE_H
#include <vector>
#include "particle.h"
#include "colloid.h"
#include <eigen3/Eigen/Eigen>
#include "staticfield.h"
#include "field.h"
#include <cmath>
#include <math.h>
#include <functional>

using namespace Eigen;
using namespace std;

namespace Maths {

Vector3d getRab(Particle *a, Particle *b);
Vector3d getNab(Particle *a, Particle *b);
int getDeltaKroneker(Particle *a, Particle *b);
int getDeltaKroneker(int a, int b);
double computeTetha(Vector3d _v);
double computeFi(Vector3d _v);
}




#endif // COMPUTE_H
