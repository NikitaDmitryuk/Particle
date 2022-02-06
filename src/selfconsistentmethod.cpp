#include "selfconsistentmethod.h"

SelfConsistentMethod::SelfConsistentMethod()
{

}

void SelfConsistentMethod::setParticleSystem(ParticleSystem *_particleSystem){
    countParticle = _particleSystem->getParticleListSize();
    particleSystem = _particleSystem;
    vectorEField = VectorXd (countParticle*3);
    vectorDipole = VectorXd (countParticle*3);
}

double SelfConsistentMethod::getClausiusMossotti(){
    double ep, es, d;
    es = particleSystem->getEnviroment()->getDielectricConst();
    d = particleSystem->getFirstParticle()->getShape()->getDiameter();
    ep = particleSystem->getFirstParticle()->getMaterialParticle()->getDielectricConst();
    return (ep - es)/(ep + 2.0*es)*d*d*d / 8.0;
}

void SelfConsistentMethod::setMatrixC(){
    MatrixXd middle(countParticle*3, countParticle*3);
    Matrix3d B;
    for (int i = 0; i < countParticle; i++) {
        for(int j = 0; j < countParticle; j++) {

            B = getMatrixB(particleSystem->getParticlei(i), particleSystem->getParticlei(j));

            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){

                    middle(k + i*3, l + j*3) = i == j ? 0.0: B(k,l);

                }
            }
        }
    }
    matrixC = 1/getClausiusMossotti()*MatrixXd::Identity(countParticle*3, countParticle*3) - middle;
}

void SelfConsistentMethod::setVectorEField(){
    Vector3d vectorE = particleSystem->getField()->getTension();
    for (int i = 0; i < countParticle; i++){
        for (int j = 0; j < 3; j++){

            vectorEField(i*3+j) = vectorE[j];

        }
    }
}

void SelfConsistentMethod::computeDipole(){
    setMatrixC();
    setVectorEField();
    //Далее решение системы линейных уравнений.
    vectorDipole = matrixC.ldlt().solve(vectorEField);
    Vector3d _vec;
    Particle *_part;

    for (int i=0; i < countParticle; i++){
        for (int j = 0; j < 3; j++){
            _vec[j] = vectorDipole[i*3+j];
        }
        _part = particleSystem->getParticlei(i);
        _part->setDipoleParticle(new Dipole(_vec));
        _part->getDipoleParticle()->setApplicationPoint(_part->getPositionParticle());
    }

}

void SelfConsistentMethod::computeTotalEnergySystem(){

}

void SelfConsistentMethod::computeEnergyParticlesInField(){

    computeDipole();

    double energyParticle, He, Hi, Hs;
    Vector3d E0, Pa, P0;

    for(auto particle : particleSystem->getParticleList())
    {
        E0 = particleSystem->getField()->getTension();
        Pa = particle->getDipoleParticle()->getDipoleVector();
        P0 = getClausiusMossotti() * E0;
        He = computeHe(particle);
        Hi = computeHi(particle);
        Hs = computeHs(particle);

        energyParticle = He + Hs + Hi;
        particle->setEnergyParticleFull(energyParticle);
        particle->setEnergyParticleHe(He);
        particle->setEnergyParticleHi(Hi);
        particle->setEnergyParticleHs(Hs);

        cout << "R: " << getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm()
             << "  He: " << He << "  Hi: "<< Hi << "  Hs: " << Hs << "  EnergySumm: " << energyParticle << endl;
    }
}

Vector3d SelfConsistentMethod::localFieldAroundParticle(Particle *_particleA){
    Vector3d vectorE(0.0, 0.0, 0.0), dipole;
    double b;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (auto particleB : particleSystem->getParticleList()){
                if(_particleA == particleB) continue;
                b = getb(_particleA, particleB, i, j);
                dipole = particleB->getDipoleParticle()->getDipoleVector();
                vectorE[i] +=  b * dipole[j];
            }
        }
    }

    return vectorE;
}

double SelfConsistentMethod::computeEnergyHsInf(Particle *_particle){
    double HsInf;
    Vector3d E0 = particleSystem->getField()->getTension();
    Vector3d P0 = getClausiusMossotti() * E0;
    double d = _particle->getShape()->getDiameter();
    HsInf = 4.0 * P0.norm() * P0.norm() / (d*d*d);

    return HsInf;
}

double SelfConsistentMethod::computeEnergyHiInf(Particle *_particle){
    double HiInf;
    Vector3d E0 = particleSystem->getField()->getTension();
    Vector3d P0 = getClausiusMossotti() * E0;
    HiInf = - 1.0 / 2.0 * P0.dot(E0);
    return HiInf;
}

double SelfConsistentMethod::computeHe(Particle *_particleA){
    Vector3d localField, dipole;
    double He;
    localField = localFieldAroundParticle(_particleA);
    dipole = _particleA->getDipoleParticle()->getDipoleVector();
    He = - 1.0 / 2.0 * localField.dot(dipole);
    return (He);
}

double SelfConsistentMethod::computeHs(Particle *_particleA){
    double d = _particleA->getShape()->getDiameter();
    double normPa = _particleA->getDipoleParticle()->getDipoleVector().norm();

    return ( 4.0 * normPa * normPa / (d * d * d) - computeEnergyHsInf(_particleA));
}

double SelfConsistentMethod::computeHi(Particle *_particleA){
    Vector3d Pa, E0;
    Pa = _particleA->getDipoleParticle()->getDipoleVector();
    E0 = particleSystem->getField()->getTension();

    return (- 1.0 / 2.0 * Pa.dot(E0) - computeEnergyHiInf(_particleA));
}

double SelfConsistentMethod::getb(Particle *a, Particle *b, int i, int j){
    double normRab = getRab(a, b).norm();
    normRab = getRab(a, b).norm();

    return ((3.0 * getNab(a, b)[i] * getNab(a, b)[j] - getDeltaKroneker(i, j))
            /( normRab * normRab * normRab )) * (1 - getDeltaKroneker(a, b));
}

Matrix3d SelfConsistentMethod::getMatrixB(Particle *a, Particle *b){
    Matrix3d B;
    for (int i=0; i< 3; i++){
        for(int j=0; j < 3; j++){
            B(i,j) = getb(a, b , i, j);
        }
    }

    return B;
}

void SelfConsistentMethod::reCalculateEnergyParticle(double _tetha){
    particleSystem->getField()->setAngleFi(_tetha);
    computeEnergyParticlesInField();
}

void SelfConsistentMethod::computeEnergyParticlesInRotatingField(){
    computeEnergyParticlesInField();
    double energyFull, energyHe, energyHi, energyHs;
    double integrationLimitA = 0.0;
    double integrationLimitB = M_PI;

    vector<double> H = computeIntegralEnergy(integrationLimitA, integrationLimitB, 200);

    energyFull = 1.0 / (integrationLimitB - integrationLimitA) * H[0];
    energyHe = 1.0 / (integrationLimitB - integrationLimitA) * H[1];
    energyHi = 1.0 / (integrationLimitB - integrationLimitA) * H[2];
    energyHs = 1.0 / (integrationLimitB - integrationLimitA) * H[3];

    cout << "computeEnergyParticlesInRotatingField()" << endl;

    ofstream fout;
    double U0 = computeU0();
    Particle *_particle = particleSystem->getParticlei(1);
    double d = _particle->getShape()->getDiameter();

    fout.open("result.txt", ios::app);
    fout << getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm() << "   " << energyFull << endl;
    fout.close();
    fout.open("Ui.txt", ios::app);
    fout << getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm() / d  << "   " << computeUe() / U0 << "   " << energyHi / U0 << endl;
    fout.close();
    fout.open("Ue.txt", ios::app);
    fout << getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm() / d << "   " << computeUe() / U0<< "   " << energyHe / U0<< endl;
    fout.close();
    fout.open("Us.txt", ios::app);
    fout << getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm() / d << "   " << computeUs() / U0<< "   " << energyHs / U0<< endl;
    fout.close();
    fout.open("Ufull.txt", ios::app);
    fout << getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm() / d << "   " << computeUfull() / U0<< "   " << energyFull / U0<< endl;
    fout.close();

    cout << getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm() / d << "   " << energyFull / U0 << endl;
}

vector<double> SelfConsistentMethod::summEnergyParticle(double tetha){

    reCalculateEnergyParticle(tetha);
    vector<double> H(4);

    H[0] = particleSystem->getFirstParticle()->getEnergyParticleFull();
    H[1] = particleSystem->getFirstParticle()->getEnergyParticleHe();
    H[2] = particleSystem->getFirstParticle()->getEnergyParticleHi();
    H[3] = particleSystem->getFirstParticle()->getEnergyParticleHs();

    return H;
}


vector<double> SelfConsistentMethod::computeIntegralEnergy(double a, double b, int n){

    double dx, HFull=0.0, He=0.0, Hi=0.0, Hs=0.0;
    vector<double> HSumm(4);
    vector<double> H(4);
    dx = fabs(b - a) / n;

    for(double x = a; x <= b - dx; x += dx){
        HSumm = summEnergyParticle(x + dx/2.0);
        HFull += HSumm[0];
        He += HSumm[1];
        Hi += HSumm[2];
        Hs += HSumm[3];
    }

    H[0] = HFull * dx;
    H[1] = He * dx;
    H[2] = Hs * dx;
    H[3] = Hi * dx;

    return H;
}


double SelfConsistentMethod::computeUe(){
    Particle *_particle = particleSystem->getParticlei(1);
    Vector3d E0 = particleSystem->getField()->getTension();
    double P0 = getClausiusMossotti() * E0.norm();
    double d = _particle->getShape()->getDiameter();
    double r = getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm();

    return -P0*P0 / (4.0 * d*d*d) * (d / r)* (d / r)* (d / r);
}

double SelfConsistentMethod::computeUs(){
    Particle *_particle = particleSystem->getParticlei(1);
    Vector3d E0 = particleSystem->getField()->getTension();
    double P0 = getClausiusMossotti() * E0.norm();
    double d = _particle->getShape()->getDiameter();
    double r = getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm();

    return P0*P0 / (4.0 * d*d*d) * (d / r)* (d / r)* (d / r) * 16.0 * getClausiusMossotti() / (d*d*d);
}

double SelfConsistentMethod::computeUfull(){
    Particle *_particle = particleSystem->getParticlei(1);
    Vector3d E0 = particleSystem->getField()->getTension();
    double P0 = getClausiusMossotti() * E0.norm();
    double d = _particle->getShape()->getDiameter();
    double r = getRab(particleSystem->getParticlei(0), particleSystem->getParticlei(1)).norm();

    return - 2.0 * P0*P0 / (4.0 * d*d*d) * (d / r)* (d / r)* (d / r) * (1.0 - 8.0 * getClausiusMossotti() / (d*d*d) );
}

double SelfConsistentMethod::computeU0(){
    Particle *_particle = particleSystem->getParticlei(1);
    Vector3d E0 = particleSystem->getField()->getTension();
    double P0 = getClausiusMossotti() * E0.norm();
    double d = _particle->getShape()->getDiameter();
    double U0 = P0*P0 / (4.0 * d*d*d);
    return U0;
}
