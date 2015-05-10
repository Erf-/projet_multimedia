#include "arene.h"

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
    Vec CS(s.x_-c.xint_, s.y_-c.yint_, s.z_-c.zint_);
    Vec CM(CS*((norm(CS)+s.radius_)/norm(CS)));
    Vec CH;
    Vec SM;
    SM = CM - CS;
    CH = _X_*pscal(CM,_X_) + _Y_*pscal(CM,_Y_);
    if (norm(CH)<=c.radius_int){
        return true;
    }
    return false;
}
void Arene::genererSphere(){
    double r = rand_a_b(c.radius_ext-Sphere::radius_)[0];
    double theta = rand_a_b(1,2*M_PI)[0];
    double psi = rand_a_b(1,2*M_PI)[1];
    Sphere s(r*sin(psi)*cos(theta),r*sin(psi)*sin(theta),r*cos(psi));
    s.draw();
}
void Arene::draw(){
    c.draw();
}
