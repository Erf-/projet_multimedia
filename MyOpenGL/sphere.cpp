#include "Sphere.h"

Sphere::Sphere (double x, double y, double z, double radius)
{
    params = gluNewQuadric();
    x_=x;
    y_=y;
    z_=z;
    radius_=radius;

}
Sphere::~Sphere(){

}

void Sphere::draw(){
    //A COMPLETER
    /*
     * on va se translater jusqu'au point de coordonnees (x, y, z)
     * puis on va tracer notre sphere en utilisant la gluSphere
     *
     */

    //transparent
    glTranslatef((float)x_,(float)y_,(float)z_);
//    glDisable( GL_CULL_FACE );
//    glEnable( GL_BLEND );
//    glDepthMask (GL_FALSE);
//    glColor4fv(Rose);

    glColor3f(3,1,2);
    gluQuadricDrawStyle(params,GLU_FILL);
//    gluQuadricTexture(params,GL_TRUE);
    gluSphere(params,radius_,30,30);
    gluDeleteQuadric(params);

//    glDepthMask (GL_TRUE);
//    glDisable( GL_BLEND );
//    glEnable( GL_CULL_FACE );
}
