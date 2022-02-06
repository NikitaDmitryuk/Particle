
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "material.h"

class Environment : public Material
{
public:
    Environment(double dielectricConst);

private:
    Material *material;
};

#endif // ENVIRONMENT_H
