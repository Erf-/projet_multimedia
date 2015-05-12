#ifndef CERCLE_TROUE_H
#define CERCLE_TROUE_H

#include <QtGui>
#include <QtOpenGL>

#include "myglwidget.h"

#include <GL/glu.h>
#include "math2.h"

using namespace math2;

class Cercle_troue
{
    GLfloat (*points_int)[3];//pointeur vers points
    GLfloat (*points_ext)[3];//pointeur vers points
public:
    GLdouble dist;
    GLdouble angle;
    GLdouble x_;
    GLdouble y_;
    GLdouble z_;
    GLdouble xint_;
    GLdouble yint_;
    GLdouble zint_;
    int nb_points;
    //Cercle_troue(GLdouble radius_int=1.0, GLdouble radius_ext=2.0, GLdouble dist=0.5, GLdouble angle=30.0, GLdouble x_=0.0, GLdouble y_=0.0, GLdouble z_=0.0);
    Cercle_troue(int nb_points=30, double radius_int=1.0, double radius_ext=3.0, double dist=0.5, double angle=30.0, double x_=0.0, double y_=0.0, double z_=0.0);
    GLdouble radius_int;
    GLdouble radius_ext;
private slots:
    bool calcul();
public slots:
    void draw();

};

#endif // CERCLE_TROUE_H
