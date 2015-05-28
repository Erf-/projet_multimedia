#include "cible.h"

Cible::Cible(int nb_points, double radius, double x, double y, double z) : Cercle(nb_points,radius,x,y,z)
{
    cint_ = Cercle(nb_points, radius/2, x, y, z);
}

void Cible::draw(){
    glColor4fv(Bleu);
    this->Cercle::draw();
    //on va dessiner cint_ en transparence
    glDisable( GL_CULL_FACE );
    glDepthMask (GL_FALSE);
    glColor4fv(Rose);
    cint_.draw();
    glDepthMask (GL_TRUE);
    glEnable( GL_CULL_FACE );
}
