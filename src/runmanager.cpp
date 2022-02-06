#include "runmanager.h"

RunManager::RunManager(ComputeMethod *_computeMethod){
    computeMethod.reset(_computeMethod);
}

RunManager::~RunManager(){

    computeMethod.~shared_ptr();

}

void RunManager::setInizialization(Particle *_particle){
    particleSystem.addParticle(_particle);
}

void RunManager::setInizialization(Material *_material){
    particleSystem.setEnviroment(_material);
}

void RunManager::setInizialization(Field *_field){
    particleSystem.setField(_field);
}

void RunManager::assembly(){
    computeMethod.get()->setParticleSystem(&particleSystem);
}

ParticleSystem *RunManager::getParticleSystem(){
    return &particleSystem;
}

void RunManager::computeDipole(){
    computeMethod.get()->computeDipole();
}

void RunManager::computeEnergyParticlesInField(){
    computeMethod.get()->computeEnergyParticlesInField();
}

void RunManager::computeEnergyParticlesInRotatingField(){
    computeMethod.get()->computeEnergyParticlesInRotatingField();
}
