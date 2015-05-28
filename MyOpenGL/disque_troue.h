#ifndef DISQUE_TROUE_H
#define DISQUE_TROUE_H

#include "cercle.h"
#include "math2.h"
#include "cible.h"
#include "trou.h"

using namespace math2;

class Disque_troue : public Cercle
{
public:
    /**
     * @brief cibles
     * @brief taille
     * on aurait pu utiliser la classe vector et directement utiliser ces methodes
     * mais on va juste utiliser un tableau car il n'y a pas nécessité de sortir
     * l'artillerie lourde. La taille des tableaux sera geree par la variable int taille.
     */
    Cible cibles_[10];//ici les cercles en questions pourront etre de type trou ou cible
    Trou trou_;
    int taille_;
    GLuint texture_;

    Disque_troue(int nb_points=30, double radius=3.0, double x=0.0, double y=0.0, double z=0.0);
    ~Disque_troue();
private slots:
    bool calculDistance(Cercle c);//calculera les distances avec les centres
    bool is_addPossible(Cible &c);
public slots:
    bool add(Cible &c);
    bool setTrou(Trou &t);
    void setTexture(const char* filename){texture_=loadtgadisplayCDV(filename);}
    void add(int n);
    void remove(Cible c);
    void draw();
};

#endif // DISQUE_TROUE_H
