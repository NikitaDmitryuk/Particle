#ifndef PARTICLE_H
#define PARTICLE_H
#include <eigen3/Eigen/Eigen>
#include "shape.h"
#include "material.h"
#include "dipole.h"
#include "memory"

using namespace Eigen;
using namespace std;

class Particle
{
public:
    Particle();
    virtual ~Particle();
    virtual Vector3d getPositionParticle()=0;
    virtual void setPositionParticle(Vector3d _position)=0;
    virtual void setNumerParticle(short _numer)=0;
    virtual short getNumerParticle()=0;
    virtual Shape *getShape()=0;
    virtual void setShape(Shape *_shape)=0;
    virtual Material *getMaterialParticle()=0;
    virtual void setMaterialParticle(Material *_material)=0;
    virtual Dipole *getDipoleParticle()=0;
    virtual void setDipoleParticle(Dipole *_dipole)=0;
    virtual string getName()=0;
    virtual void setEnergyParticleFull(double _energy)=0;
    virtual double getEnergyParticleFull()=0;
    virtual void setEnergyParticleHi(double _energy)=0;
    virtual double getEnergyParticleHi()=0;
    virtual void setEnergyParticleHs(double _energy)=0;
    virtual double getEnergyParticleHs()=0;
    virtual void setEnergyParticleHe(double _energy)=0;
    virtual double getEnergyParticleHe()=0;
protected:
    short numerParticle;
    string name;
    Vector3d positionParticle;
    shared_ptr<Shape> shapeParticle;
    shared_ptr<Material> materialParticle;
    shared_ptr<Dipole> dipoleParticle;
    double energyParticleFull;
    double energyParticleHi;
    double energyParticleHs;
    double energyParticleHe;
};

#endif // PARTICLE_H
