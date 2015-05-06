#include "cercle_troue.h"

Cercle_troue::Cercle_troue(double radius_int, double radius_ext, double dist, double angle, double x_, double y_, double z_){
    this->radius_int = GLdouble(radius_int);
    this->radius_ext = GLdouble(radius_ext);
    this->dist = GLdouble(dist);
    this->angle = GLdouble(angle);
    this->x_ = GLdouble(x_);
    this->y_ = GLdouble(y_);
    this->z_ = GLdouble(z_);
}

/**
 * @brief Cercle_troue::calcul
 * @param nb_points
 * @return true ou false
 * dans cette methode:
 * - on calcul les coordonnees des points necessaires a la creation des quadstrips
 * permettant le rendu "cercle troue"
 * - on retourne la valeur "false" si le calcul n'a pas pu etre effectue et "true" sinon
 */
bool Cercle_troue::calcul(GLdouble nb_points)
{
    /**
     * @brief radius_step relie au nombre de points demande
     *
     */
    GLdouble radius_step = 0;
    if (nb_points!=0)
    {
        radius_step = 2*M_PI/nb_points;
        for(int i = 1; i*radius_step<=2*M_PI; i++){
            //points_int[i]={radius_int*cos(i*radius_step),radius_int*sin(i*radius_step),z_};
        }
        for(int i = 1; i*radius_step<=2*M_PI; i++){
            //points_ext[i]={radius_ext*cos(i*radius_step),radius_ext*sin(i*radius_step),z_};
        }
        return true;
    }
    return false;
}
/**
 * @brief Cercle_troue::draw
 * methode utilisant les coordonnees claculees dans Cercle_troue::calcul
 * pour dessiner le cercle troue
 */
/*Cercle_troue::draw()
{
}
*/
