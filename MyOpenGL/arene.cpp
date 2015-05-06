#include "arene.h"

using namespace math2;

Arene::Arene()
{
}
/**
 * @brief Arene::sphere_axee
 * @param s
 * methode emettant le signal permettant de savoir
 * si la sphere est dans l'axe du "trou" de l'arene ou pas
 */
void Arene::sphere_axee(Sphere &s){//A TERMINER
    if(is_s_in_hole(s)){
        emit sphere_axee(s);
    }
}
bool Arene::is_s_in_hole(Sphere &s){
    Vec x(1.0, 0.0, 0.0);
    Vec y(0.0, 1.0, 0.0);
    Vec z(0.0, 0.0, 1.0);
    Vec CS(s.x_-c.xint_, s.y_-c.yint_, s.z_-c.zint_);
    Vec CM(CS*((norm(CS)+s.radius_)/norm(CS)));
    Vec CH;
    Vec SM;
    SM = CM - CS;
    CH = x*pscal(CM,x) + y*pscal(CM,y);
    if (norm(CH)<=c.radius_int){
        return true;
    }
    return false;
}
