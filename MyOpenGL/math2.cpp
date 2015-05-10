#include "math2.h"

Vec::Vec(double x, double y, double z){
    x_=x;
    y_=y;
    z_=z;
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
}
