#include "paroi.h"

Paroi::Paroi(int nb_points, double radius, double x, double y, double z) : Cercle(nb_points,radius,x,y,z)
{
}
void Paroi::draw()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDisable( GL_CULL_FACE );
    glEnable( GL_BLEND );
    glDepthMask(GL_TRUE);
    glBegin(GL_QUAD_STRIP);
    glColor4fv(Jaune);
    for(int i=0;i<nb_points_-1;i++){
        glVertex3d(points_[i][0],points_[i][1],points_[i][2]);
        glVertex3d(points_[i][0],points_[i][1],points_[i][2]+h);
        glVertex3d(points_[i+1][0],points_[i+1][1],points_[i+1][2]);
        glVertex3d(points_[i+1][0],points_[i+1][1],points_[i+1][2]+h);
    }
    glVertex3f(points_[0][0],points_[0][1],points_[0][2]);
    glVertex3f(points_[0][0],points_[0][1],points_[0][2]+h);
    glEnd();
    glDisable( GL_BLEND );
    glEnable( GL_CULL_FACE );
    glDepthMask(GL_FALSE);
}
