#include "cible.h"

Cible::Cible(int nb_points, double radius, double x, double y, double z) : Cercle(nb_points,radius,x,y,z)
{
    cint_ = Cercle(nb_points, radius/2, x, y, z);
}

void Cible::draw(){
    this->Cercle::draw();
    //on va dessiner cint_ en transparence
    cint_.draw();
}
