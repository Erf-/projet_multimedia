#include "paroi.h"

Paroi::Paroi(int nb_points, double radius, double x, double y, double z) : Cercle(nb_points,radius,x,y,z)
{
}
void Paroi::draw()
{
    glDisable( GL_CULL_FACE );
    glDepthMask(GL_FALSE);

    glColor4fv(Jaune);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<nb_points_-1;i++){
        glVertex3d(points_[i][0],points_[i][1],points_[i][2]);
        glVertex3d(points_[i][0],points_[i][1],points_[i][2]+h);
        glVertex3d(points_[i+1][0],points_[i+1][1],points_[i+1][2]);
        glVertex3d(points_[i+1][0],points_[i+1][1],points_[i+1][2]+h);
    }
    glVertex3f(points_[0][0],points_[0][1],points_[0][2]);
    glVertex3f(points_[0][0],points_[0][1],points_[0][2]+h);
    glEnd();

    glEnable( GL_CULL_FACE );
    glDepthMask(GL_TRUE);
}
