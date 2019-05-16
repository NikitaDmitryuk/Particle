#include "colloid.h"

Colloid::Colloid(short numer, string _name, Vector3d _position, Shape *_shape, Material *_material)
{
    numerParticle = numer;
    name = _name;
    positionParticle = _position;
    shapeParticle.reset(_shape);
    materialParticle.reset(_material);
}

Colloid::~Colloid(){

}

void Colloid::setPositionParticle(Vector3d _position){
    positionParticle = _position;
}

Vector3d Colloid::getPositionParticle(){
    return positionParticle;

}

void Colloid::setDipoleParticle(Dipole *_dipole){
    dipoleParticle.reset(_dipole);
}

Dipole *Colloid::getDipoleParticle(){
    return dipoleParticle.get();
}

void Colloid::setMaterialParticle(Material *_material){
    materialParticle.reset(_material);
}

Material *Colloid::getMaterialParticle(){
    return materialParticle.get();
}

void Colloid::setNumerParticle(short _numer){
    numerParticle = _numer;
}

short Colloid::getNumerParticle(){
    return numerParticle;
}

void Colloid::setShape(Shape *_shape){
    shapeParticle.reset(_shape);
}

Shape *Colloid::getShape(){
    return shapeParticle.get();
}

string Colloid::getName(){
    return name;
}

void Colloid::setEnergyParticleFull(double _energy){
    energyParticleFull = _energy;
}

double Colloid::getEnergyParticleFull(){
    return energyParticleFull;
}

void Colloid::setEnergyParticleHi(double _energy){
    energyParticleHi = _energy;
}

double Colloid::getEnergyParticleHi(){
    return energyParticleHi;
}

void Colloid::setEnergyParticleHe(double _energy){
    energyParticleHe = _energy;
}

double Colloid::getEnergyParticleHe(){
    return energyParticleHe;
}

void Colloid::setEnergyParticleHs(double _energy){
    energyParticleHs = _energy;
}

double Colloid::getEnergyParticleHs(){
    return energyParticleHs;
}
