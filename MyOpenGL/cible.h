#ifndef CIBLE_H
#define CIBLE_H

#include "cercle.h"

class Cible : public Cercle
{
    Cercle cint_;
public:
    Cible(int nb_points=30, double radius=3.0, double x=0.0, double y=0.0, double z=0.0);
    void draw();
};

#endif // CIBLE_H
