#ifndef PAROI_H
#define PAROI_H

#include "cercle.h"
#include "math2.h"

using namespace math2;

class Paroi : public Cercle
{
    static const GLdouble h = 0.5;//hauteur
public:
    Paroi(int nb_points=30, double radius=3.0, double x=0.0, double y=0.0, double z=0.0);
    void draw();
};

#endif // PAROI_H
