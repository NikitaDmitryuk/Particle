#ifndef SELFCONSISTENTMETHOD_H
#define SELFCONSISTENTMETHOD_H
#include "particlesystem.h"
#include <eigen3/Eigen/Eigen>
#include "shape.h"
#include "material.h"
#include "dipole.h"
#include "memory"
#include "maths.h"
#include "computemethod.h"
#include "dipole.h"
#include <functional>
#include <fstream>

using namespace Eigen;
using namespace std;
using namespace Maths;

class SelfConsistentMethod: public ComputeMethod
{
public:
    SelfConsistentMethod();
    void setParticleSystem(ParticleSystem *_particleSystem);
    void computeDipole();
    void computeTotalEnergySystem();
    void computeEnergyParticlesInField();
    void computeEnergyParticlesInRotatingField();

private:
    int countParticle;
    MatrixXd matrixC;
    VectorXd vectorEField;
    VectorXd vectorDipole;
    ParticleSystem *particleSystem;

    double getClausiusMossotti();
    void setMatrixC();
    void setVectorEField();
    double computeHe(Particle *a);
    double computeHs(Particle *a);
    double computeHi(Particle *a);
    double getb(Particle *a, Particle *b, int i, int j);
    Matrix3d getMatrixB(Particle *a, Particle *b);
    Vector3d localFieldAroundParticle(Particle *_particleA);
    void reCalculateEnergyParticle(double _tetha);
    vector<double> summEnergyParticle(double tetha);
    vector<double> computeIntegralEnergy(double a, double b, int n);
    double computeEnergyHsInf(Particle *_particle);
    double computeEnergyHiInf(Particle *_particle);
    double computeU0();


    double computeUe();
    double computeUs();
    double computeUfull();
};

#endif // SELFCONSISTENTMETHOD_H
