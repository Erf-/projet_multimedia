#ifndef CERCLE_TROUE_H
#define CERCLE_TROUE_H

#include <QtGui>
#include <QtOpenGL>

#include "myglwidget.h"

#include <GL/glu.h>

class Cercle_troue
{
    GLdouble dist;
    GLdouble angle;
    GLdouble z;
    GLfloat* points_int[3] ;//pointeur vers points
    GLfloat* points_ext[3] ;//pointeur vers points
public:
    Cercle_troue(GLdouble radius_int=1.0, GLdouble radius_ext=2.0, GLdouble dis=0.5, GLdouble angle=30.0, GLdouble z=0.0);
    GLdouble radius_int;
    GLdouble radius_ext;
public slots:
    bool calcul(GLdouble nb_points);//ici on va calculer les points neccesaires a la creation du disque troue
    draw();

};

#endif // CERCLE_TROUE_H
