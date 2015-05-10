#include "math2.h"

Vec::Vec(double x, double y, double z){
    x_=GLdouble(x);
    y_=GLdouble(y);
    z_=GLdouble(z);
}

namespace math2
{
    GLdouble pscal(Vec a, Vec b){
        return Math2::pscal(a, b);
    }
    GLdouble norm(Vec a){
        return Math2::norm(a);
    }
    /*GLdouble dist(Vec a, Vec b){
        return Math2::dist(a, b);
    }*/
}
