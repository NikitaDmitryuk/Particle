#ifndef SPACE_H
#define SPACE_H
#include <vector>
#include "particle.h"
#include "field.h"
#include <memory>
#include "print.h"

using namespace std;
class ParticleSystem
{
public:
    ParticleSystem();
    ~ParticleSystem();
    void addParticle(Particle *_particle);
    void setField(Field *_field);
    void setEnviroment(Material *_material);
    Particle *getFirstParticle();
    Particle *getParticlei(int n);
    Field *getField();
    Material *getEnviroment();
    int getParticleListSize();
    void setTotalEnergySystem(double _energy);
    double getTotalEnergySystem();
    vector<Particle*> getParticleList();

private:
    vector<Particle*> particleList;
    shared_ptr<Field> field;
    shared_ptr<Material> enviroment;
    double totalEnergySystem;
};

#endif // SPACE_H
