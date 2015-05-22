#include "trou.h"

Trou::Trou(int nb_points, double radius, double x, double y, double z) : Cercle(nb_points, radius, x, y, z)
{
}

/*bool Trou::addVoisin(Trou v){
    if (norm(Vec(v.x_-x_, v.y_-y_, v.z_-z_))<=2*radius_)
        return false;
    voisins_[nb_voisins_]=v;
    nb_voisins_++;
    triVoisins();
    return true;
}

void Trou::triVoisins(){

}
*/
