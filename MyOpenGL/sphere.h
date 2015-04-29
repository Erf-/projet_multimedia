

#ifndef SPHERE_H
#define SPHERE_H

#include <QGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include <GL/glu.h>

// La sphère est une spécialisation d'un sphéroide.
class Sphere
{
    GLUquadric* params = gluNewQuadric();

public :
    Sphere(GLdouble x, GLdouble y, GLdouble z);
    ~Sphere () ;
    GLdouble radius_;
    GLdouble x_;
    GLdouble y_;
    GLdouble z_;

public slots:
    bool texture(GLuint &textureId);
    draw();

protected:

};
