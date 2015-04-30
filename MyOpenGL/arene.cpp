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
    if(is_s_in_hole()){
        emit sphere_axee(s);
    }
}
bool Arene::is_s_in_hole(Sphere &s){
    return true;
}
