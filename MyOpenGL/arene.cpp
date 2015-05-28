#include "arene.h"

Arene::Arene(int nb_points, double radius, double x, double y, double z)
{
    d_=Disque_troue(nb_points,radius,x,y,z);
    p_=Paroi(nb_points,radius,x,y,z);
    nbs_=0;
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
    Vec CS(s.x_-d_.trou_.x_, s.y_-d_.trou_.y_, s.z_-d_.trou_.z_);
    Vec CM(CS*((norm(CS)+s.radius_)/norm(CS)));
    Vec CH;
    Vec SM;
    SM = CM - CS;
    CH = _X_*pscal(CM,_X_) + _Y_*pscal(CM,_Y_);
    if (norm(CH)<=d_.trou_.radius_ ){
        return true;
    }
    return false;
}
void Arene::genererSphere(){
    srand(time(NULL));
    double r = rand_a_b(d_.radius_-Sphere::radius_)[0];
    double theta = rand_a_b(1,2*M_PI)[0];
    double psi = rand_a_b(1,2*M_PI)[1];
    Sphere s(r*sin(psi)*cos(theta),r*sin(psi)*sin(theta),r*cos(psi));
    s.draw();
}
void Arene::draw(){
    d_.draw();
    p_.draw();
}
