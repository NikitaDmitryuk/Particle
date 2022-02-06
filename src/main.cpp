#include <vector>
#include "particle.h"
#include "iostream"
#include "colloid.h"
#include <eigen3/Eigen/Eigen>
#include "runmanager.h"
#include "selfconsistentmethod.h"
#include "rotatingfield.h"

using namespace Eigen;
using namespace std;

int main(int argc, char *argv[])
{
    ofstream fout;

      fout.open("Us.txt", ios::trunc);
      fout.close();
      fout.open("Ue.txt", ios::trunc);
      fout.close();
      fout.open("Ufull.txt", ios::trunc);
      fout.close();
      fout.open("U.txt", ios::trunc);
      fout.close();
      fout.open("Ui0.txt", ios::trunc);
      fout.close();
      fout.open("Us0.txt", ios::trunc);
      fout.close();
      fout.open("Ufull0.txt", ios::trunc);
      fout.close();
      fout.open("result.txt", ios::trunc);
      fout.close();
      fout.open("Ui.txt", ios::trunc);
      fout.close();

    RunManager runManager(new SelfConsistentMethod());
    runManager.setInizialization(new Colloid(0, "Colloid", Vector3d (0.0, 0.0, 0.0),
                                             new Shape(2.0), new Material(2.95)));
    runManager.setInizialization(new Colloid(1, "Colloid", Vector3d (2.01, 0.0, 0.0),
                                             new Shape(2.0), new Material(2.95)));
    runManager.setInizialization(new Material(80.1));
    runManager.setInizialization(new RotatingField(Vector3d (1e3, 0.0, 0.0)));
    runManager.assembly();
    //runManager.computeDipole();

    for (double i = 2.01; i <= 20.0; i += 0.05){
        runManager.getParticleSystem()->getParticlei(1)->setPositionParticle(Vector3d (i, 0.0, 0.0));
        runManager.computeEnergyParticlesInRotatingField();
    }

//    double r = 0;
//    for (int i = 0; i < 20.0; i ++){
//        if (i < 10){
//            r = pow(10, std::log10(2.01) + i*0.01);
//        }
//        else if(i >= 10){
//            r = pow(10, std::log10(2.5304) + (i-10) * 0.1);
//        }
//        //cout << r << endl;
//        runManager.getParticleSystem()->getParticlei(1)->setPositionParticle(Vector3d (r, 0.0, 0.0));
//        runManager.computeEnergyParticlesInRotatingField();
//    }

    return 0;
}

