#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "particle.h"
#include "dipole.h"
#include "field.h"
#include "material.h"
#include "shape.h"
#include <eigen3/Eigen/Eigen>
#include <memory>
#include "particlesystem.h"
#include "selfconsistentmethod.h"

using namespace Eigen;

class RunManager
{
public:
    RunManager(ComputeMethod *_computeMethod);
    ~RunManager();
    void setInizialization(Particle *_particle);
    void setInizialization(Material *_material);
    void setInizialization(Field *_field);
    void assembly();
    void computeDipole();
    void computeEnergyParticlesInField();
    void computeEnergyParticlesInRotatingField();

    ParticleSystem *getParticleSystem();


private:
    ParticleSystem particleSystem;
    shared_ptr<ComputeMethod> computeMethod;
};

#endif // DIRECTOR_H
