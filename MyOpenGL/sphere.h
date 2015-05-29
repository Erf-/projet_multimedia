#ifndef SPHERE_H
#define SPHERE_H

#include <QGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include <GL/glu.h>
#include "math2.h"

using namespace math2;

class Sphere
{
    GLUquadric* params;

public :
    Sphere(double x=0.0, double y=0.0, double z=0.0,double radius= 0.2);
    ~Sphere () ;
    GLdouble radius_;
    GLdouble x_;
    GLdouble y_;
    GLdouble z_;

public slots:
    bool texture(GLuint &textureId);
    void draw();

protected:

};

#endif //SPHERE_H
