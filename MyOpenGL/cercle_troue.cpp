#include "cercle_troue.h"

Cercle_troue::calcul(GLdouble nb_points)
{
    GLdouble radius_step = 0;
    if (nb_points!=0)
    {
        radius_step = 2*Pi/nb_points;
        for(int i = 1; i*radius_step<=2*Pi; i++){
            points_int[i]={radius_int*cos(i*radius_step),radius_int*sin(i*radius_step),z};
        }
        for(int i = 1; i*radius_step<=2*Pi; i++){
            points_ext[i]={radius_ext*cos(i*radius_step),radius_ext*sin(i*radius_step),z};
        }
    }
}

Cercle_troue::draw()
{
}
