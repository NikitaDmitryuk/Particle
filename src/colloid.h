#ifndef COLLOID_H
#define COLLOID_H
#include "particle.h"


class Colloid: public Particle
{
public:
    Colloid(short numer, string _name, Vector3d _position, Shape *_shape, Material *_material);
    ~Colloid();
    Vector3d getPositionParticle();
    void setPositionParticle(Vector3d _position);
    void setNumerParticle(short _numer);
    short getNumerParticle();
    Shape *getShape();
    void setShape(Shape *_shape);
    Material *getMaterialParticle();
    void setMaterialParticle(Material *_material);
    Dipole *getDipoleParticle();
    void setDipoleParticle(Dipole *_dipole);
    string getName();
    void setEnergyParticleFull(double _energy);
    double getEnergyParticleFull();
    void setEnergyParticleHe(double _energy);
    double getEnergyParticleHe();
    void setEnergyParticleHi(double _energy);
    double getEnergyParticleHi();
    void setEnergyParticleHs(double _energy);
    double getEnergyParticleHs();
};

#endif // COLLOID_H
