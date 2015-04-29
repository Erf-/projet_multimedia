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
Arene::sphere_axee(Sphere &s){//A TERMINER
    if((s.x_+s.radius_<c.radius_int)&&(s.y_+s.radius_<c.radius_int)){
        emit sphere_axee(s);
    }
}
