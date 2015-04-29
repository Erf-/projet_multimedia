#include "cercle_troue.h"

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
        radius_step = 2*Pi/nb_points;
        for(int i = 1; i*radius_step<=2*Pi; i++){
            points_int[i]={radius_int*cos(i*radius_step),radius_int*sin(i*radius_step),z};
        }
        for(int i = 1; i*radius_step<=2*Pi; i++){
            points_ext[i]={radius_ext*cos(i*radius_step),radius_ext*sin(i*radius_step),z};
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
Cercle_troue::draw()
{
}
