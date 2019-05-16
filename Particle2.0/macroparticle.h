#ifndef MACROPARTICLE_H
#define MACROPARTICLE_H

#include "particle.h"

class MacroParticle
{
public:
    MacroParticle();
    ~MacroParticle();
    Vector3d getPosition();
    void setPosition(Vector3d p);
    void setNumerParticle(short n);
    short getNumerParticle();
    Shape *getShape();
    void setShape(Shape *s);
    Material *getMaterialParticle();
    void setMaterialParticle(Material *m);
    Dipole *getDipoleParticle();
    void setDipoleParticle(Dipole *d);
};

#endif // MACROPARTICLE_H
