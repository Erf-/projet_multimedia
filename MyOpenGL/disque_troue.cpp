#include "disque_troue.h"

Disque_troue::Disque_troue()
{
    taille_=0;
}
/**
 * @brief Disque_troue::calculDistance
 * @param c
 * @param d
 * @return true ou false si la distance entre les centres permet de creer un cercle interieur
 * la valeur calculee sera implementee dans la variable d
 */
bool Disque_troue::calculDistance(Cercle c, double &d){
    Vec v_0 = Vec(this->x_-c.x_, this->y_-c.y_, this->z_-c.z_);
    Vec v = (v_0/norm(v_0))*(norm(v_0+c.radius_));
    if(norm(v)<=this->radius_){
        d=norm(v);
        return true;
    }
    return false;
}
/**
 * @brief Disque_troue::calculAngle
 * @param c
 * @param a
 * @return true ou false selon la reussite de l'operation
 * la valeur calculee sera implementee dans la variable d
 */
bool Disque_troue::calculAngle(Cercle c, double &a){
    // a faire
}
/**
 * @brief Disque_troue::add
 * @param c
 * @return true ou false selon la reussite de l'operation
 */
bool Disque_troue::add(Cercle c){
    double d;
    double a;
    if (calculDistance(c, d)){
        cercles_[taille_]=c;
        dist_[taille_]=d;
        angle_[taille_]=a;
        taille_++;
        return true;
    }
    return false;
}
