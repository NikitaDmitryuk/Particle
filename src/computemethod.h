#ifndef COMPUTEMETHOD_H
#define COMPUTEMETHOD_H
#include "particlesystem.h"

class ComputeMethod
{
public:
    ComputeMethod();
    virtual ~ComputeMethod();
    virtual void computeDipole()=0;
    virtual void setParticleSystem(ParticleSystem *_particleSystem)=0;
    virtual void computeTotalEnergySystem()=0;
    virtual void computeEnergyParticlesInField()=0;
    virtual void computeEnergyParticlesInRotatingField()=0;
};

#endif // COMPUTEMETHOD_H
