#ifndef DISQUE_TROUE_H
#define DISQUE_TROUE_H

#include "cercle.h"
#include "math2.h"

using namespace math2;

class Disque_troue : public Cercle
{
public:
    /**
     * @brief cercles
     * @brief taille
     * on aurait pu utiliser la classe vector et directement utiliser ces methodes
     * mais on va juste utiliser un tableau car il n'y a pas nécessité de sortir
     * l'artillerie lourde. La taille des tableaux sera geree par la variable int taille.
     */
    Cercle cercles_[];
    int taille_;
    GLdouble dist_[];
    GLdouble angle_[];
    
    Disque_troue();
private slots:
    bool calculDistance(Cercle c, double &d);//calculera les distances avec les centres
    bool calculAngle(Cercle c, double &a);//calculera les angles
    bool calcul();
public slots:
    bool add(Cercle c);
    bool remove(Cercle c);
    void draw();
};

#endif // DISQUE_TROUE_H
