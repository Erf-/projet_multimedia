#include "math2.h"

Vec::Vec(double x, double y, double z){
    x_=x;
    y_=y;
    z_=z;
}
/**
 * @brief Vec::angle
 * @param v
 * @return
 * ici on ne retourne que la valeur absolue de l'angle
 */
GLdouble Vec::angle(Vec v){
    Vec a = Vec(x_,y_,z_)*(1/normV());
    Vec b = v*(1/v.normV());
    if(a.pscalV(b.orth())*a.pscalV(b.orth())!=1.0){
        return acos(a.pscalV(b));
    }
    return M_PI/2;
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
    double * rand_a_b(double b, double a, int n){
        srand(time(NULL));
        double res[n+1];
        for(int i=0; i<n; i++){
            res[i]=(rand()/(double)RAND_MAX)*(b-a) +a;
        }
        return res;
    }
    GLdouble angle(Vec u, Vec v){
        return u.angle(v);
    }

}
