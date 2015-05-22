#ifndef CERCLE_H
#define CERCLE_H

#include "math2.h"

class Cercle
{
public:
    GLfloat (*points_)[3];
    GLdouble x_;
    GLdouble y_;
    GLdouble z_;
    int nb_points_;
    GLdouble radius_;

    Cercle(int nb_points=30, double radius=3.0, double x=0.0, double y=0.0, double z=0.0);
private slots:
    bool calcul();
public slots:
    void draw();
};

#endif // CERCLE_H
