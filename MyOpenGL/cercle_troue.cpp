#include "cercle_troue.h"
#define _USE_MATH_DEFINES

Cercle_troue::Cercle_troue(int nb_points, double radius_int, double radius_ext, double dist, double angle, double x_, double y_, double z_){
    this->radius_int = radius_int;
    this->radius_ext = radius_ext;
    this->dist = dist;
    this->angle = angle;
    this->x_ = x_;
    this->y_ = y_;
    this->z_ = z_;
    this->nb_points=nb_points;
    points_ext = new GLfloat [nb_points][3];
    points_int = new GLfloat [nb_points][3];
    calcul();
//    qDebug()<<cos(2*M_PI/nb_points)<<" "<<sin(2*M_PI/nb_points)<<" "<<cos(2*M_PI/nb_points)*cos(2*M_PI/nb_points)+sin(2*M_PI/nb_points)*sin(2*M_PI/nb_points);
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
bool Cercle_troue::calcul()
{
    /**
     * @brief radius_step relie au nombre de points demande
     *
     */
    double radius_step = 0;
    if (nb_points!=0)
    {
        radius_step = 2*M_PI/nb_points;
        points_ext[0][0]=radius_ext;
        points_ext[0][1]=0;
        points_ext[0][2]=z_;
        points_int[0][0]=radius_int+dist*cos(angle*M_PI/180);
        points_int[0][1]=0+dist*sin(angle*M_PI/180);
        points_int[0][2]=z_;
        for(int i = 1; i<nb_points; i++){
//            points_int[i]={radius_int*cos(i*radius_step),radius_int*sin(i*radius_step),z_};
//            points_ext[i]={radius_ext*cos(i*radius_step),radius_ext*sin(i*radius_step),z_};
            points_int[i][0]=radius_int*cos(i*radius_step)+dist*cos(angle*M_PI/180);
            points_int[i][1]=radius_int*sin(i*radius_step)+dist*sin(angle*M_PI/180);
            points_int[i][2]=z_;
            points_ext[i][0]=radius_ext*cos(i*radius_step);
            points_ext[i][1]=radius_ext*sin(i*radius_step);
            points_ext[i][2]=z_;
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
void Cercle_troue::draw()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDisable( GL_CULL_FACE );
    glEnable( GL_BLEND );
    glDepthMask (GL_FALSE);
    glColor4fv(Rose);
    glBegin(GL_QUAD_STRIP);
    for(int i=0;i<nb_points-1;i++){
        glVertex3f(points_int[i][0],points_int[i][1],points_int[i][2]);
        glVertex3f(points_ext[i][0],points_ext[i][1],points_ext[i][2]);
        glVertex3f(points_int[i+1][0],points_int[i+1][1],points_int[i+1][2]);
        glVertex3f(points_ext[i+1][0],points_ext[i+1][1],points_ext[i+1][2]);
    }
    glVertex3f(points_int[0][0],points_int[0][1],points_int[0][2]);
    glVertex3f(points_ext[0][0],points_ext[0][1],points_ext[0][2]);
//    int i=0;
//    glVertex3f(points_int[i][0],points_int[i][1],points_int[i][2]);
//    glVertex3f(points_ext[i][0],points_ext[i][1],points_ext[i][2]);
//    glVertex3f(points_ext[i+1][0],points_ext[i+1][1],points_ext[i+1][2]);
//    glVertex3f(points_int[i+1][0],points_int[i+1][1],points_int[i+1][2]);
    glEnd();
//    qDebug()<<points_int[i][0]<<" "<<points_int[i][1]<<" "<<points_int[i][2];

    glDepthMask (GL_TRUE);
    glDisable( GL_BLEND );
    glEnable( GL_CULL_FACE );


//    glDisable( GL_TEXTURE_2D );
//    glEnable( GL_CULL_FACE );
}
