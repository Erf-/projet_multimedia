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

    //Vec(GLdouble x_=0.0, GLdouble y_=0.0, GLdouble z_=0.0);
    Vec(double x=0.0, double y=0.0, double z=0.0);
    GLdouble pscalV(Vec v){return v.x_*x_+v.y_*y_+v.z_*z_;}
    GLdouble normV(){return sqrt(pscalV(Vec(x_,y_,z_)));}
    Vec operator -(Vec v){return Vec(x_-v.x_, y_-v.y_, z_-v.z_);}
    Vec operator +(Vec v){return Vec(x_+v.x_, y_+v.y_, z_+v.z_);}
    Vec operator *(Vec v){return Vec(y_*v.z_-z_*v.y_,-x_*v.z_+z_*v.x_,x_*v.y_-y_*v.x_);}
    Vec operator *(int k){return Vec(x_*k, y_*k, z_*k);}
    //GLdouble distV(Vec v){return (Vec(x_, y_, z_) - v).normV();}
};

class Math2
    {
    public:
        //Math2();
        static GLdouble pscal(Vec a, Vec b){return a.pscalV(b);}
        static GLdouble norm(Vec a){return a.normV();}
        //static GLdouble dist(Vec a, Vec b){return b.distV(a);}
    };
namespace math2 {
    static Vec _X_ = Vec(1.0, 0.0, 0.0);
    static Vec _Y_ = Vec(0.0, 1.0, 0.0);
    static Vec _Z_ = Vec(0.0, 0.0, 1.0);
    GLdouble pscal(Vec a, Vec b);
    GLdouble norm(Vec a);
    //GLdouble dist(Vec a, Vec b);
}

#endif // MATH2_H
