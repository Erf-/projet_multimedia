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
Cercle::Cercle(int nb_points, double radius, double x, double y, double z)
{
    this->radius_ = radius;
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
    this->nb_points_=nb_points;
    points_ = new GLfloat [nb_points][3];
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
        points_[0][0]=radius_+x_;
        points_[0][1]=0+y_;
        points_[0][2]=z_;
        for(int i = 1; i<nb_points_; i++){
            points_[i][0]=radius_*cos(i*radius_step)+x_;
            points_[i][1]=radius_*sin(i*radius_step)+y_;
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
    glDisable( GL_CULL_FACE );
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<nb_points_;i++){
        glVertex3d(points_[i][0],points_[i][1],points_[i][2]);
    }
    glEnd();
    glEnable( GL_CULL_FACE );
}
