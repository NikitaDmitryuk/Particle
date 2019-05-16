#include "maths.h"


Vector3d Maths::getRab(Particle *a, Particle *b){
    return a->getPositionParticle() - b->getPositionParticle();
}

Vector3d Maths::getNab(Particle *a, Particle *b){
    Vector3d n = a->getPositionParticle() - b->getPositionParticle();
    n = n.normalized();
    return n;

}

int Maths::getDeltaKroneker(Particle *a, Particle *b){
    return a == b ? 1: 0;
}

int Maths::getDeltaKroneker(int a, int b){
    return a == b ? 1: 0;
}

double Maths::computeTetha(Vector3d _v){
    return acos(_v[2] / _v.norm());
}

double Maths::computeFi(Vector3d _v){
    return atan(_v[1] / _v[0]);
}

