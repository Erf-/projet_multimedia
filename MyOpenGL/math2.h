#ifndef MATH2_H
#define MATH2_H

#include <math.h>
#include <QtGui>
#include <QtOpenGL>

class Vec{
public:
    GLdouble x_;
    GLdouble y_;
    GLdouble z_;

    Vec(x_=0.0, y_=0.0, z_=0.0);
    GLdouble pscal(Vec v){return v.x_*x_+v.y_*y_+v.z_*z_;}
    GLdouble norm(){return sqrt(pscal(v));}
    Vec operator -(Vec v){return Vec(x_-v.x_, y_-v.y_, z_-v.z_);}
    Vec operator +(Vec v){return Vec(x_+v.x_, y_+v.y_, z_+v.z_);}
    Vec operator *(Vec v){return Vec(y_*v.z_-z_*v.y_,-x*v.z_+z*v.x_,x_*v.y_-y_*v.x_);}
    GLdouble dist(Vec v){return (this - v)->norm();}
};

class Math2
{
public:
    //Math2();
    //pscal()
};

#endif // MATH2_H
