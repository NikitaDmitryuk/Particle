#include "particlesystem.h"

ParticleSystem::ParticleSystem()
{

}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::setEnviroment(Material *_material){
    enviroment.reset(_material);
}

void ParticleSystem::setField(Field *_field){
    field.reset(_field);
}

void ParticleSystem::addParticle(Particle *_particle){
    particleList.push_back(_particle);
}

Material *ParticleSystem::getEnviroment(){
    return enviroment.get();
}

Field *ParticleSystem::getField(){
    return field.get();
}

Particle *ParticleSystem::getFirstParticle(){
    return particleList.front();
}

int ParticleSystem::getParticleListSize(){
    return  static_cast<int>(particleList.size());
}

Particle *ParticleSystem::getParticlei(int n){
    return particleList.operator[](static_cast<unsigned long>(n));
}

void ParticleSystem::setTotalEnergySystem(double _energy){
    totalEnergySystem = _energy;
}
double ParticleSystem::getTotalEnergySystem(){
    return totalEnergySystem;
}

vector<Particle*> ParticleSystem::getParticleList(){
    return particleList;
}
