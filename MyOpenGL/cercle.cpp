#include "cercle.h"

/**
 * @brief Cercle::Cercle
 * @param nb_points_
 * @param radius_
 * @param x_
 * @param y_
 * @param z_
 * dans le constructeur de la classe Cercle, on initialise le tableau de poins via
 * l'appele de la methode calcul
 */
Cercle::Cercle(int nb_points_=30, double radius_=3.0, double x_=0.0, double y_=0.0, double z_=0.0)
{
    this->radius_ = radius_;
    this->x_ = x_;
    this->y_ = y_;
    this->z_ = z_;
    this->nb_points_=nb_points_;
    points_ = new GLfloat [nb_points_][3];
    calcul();
}
/**
 * @brief Cercle_troue::calcul
 * @param nb_points_
 * @return true ou false
 * dans cette methode:
 * - on calcul les coordonnees des points necessaires a la creation des quadstrips
 * permettant le rendu "cercle troue"
 * - on retourne la valeur "false" si le calcul n'a pas pu etre effectue et "true" sinon
 */
bool Cercle::calcul()
{
    /**
     * @brief radius_step relie au nombre de points demande
     *
     */
    double radius_step = 0;
    if (nb_points_!=0)
    {
        radius_step = 2*M_PI/nb_points_;
        points_[0][0]=radius_;
        points_[0][1]=0;
        points_[0][2]=z_;
        for(int i = 1; i<nb_points_; i++){
            points_[i][0]=radius_*cos(i*radius_step);
            points_[i][1]=radius_*sin(i*radius_step);
            points_[i][2]=z_;
        }
        return true;
    }
    return false;
}
/**
 * @brief Cercle::draw
 * methode de dessin du cercle
 * ne pas confondre disque et cercle.
 * en effet un disque est un cercle plein
 */
void Cercle::draw()
{
}
