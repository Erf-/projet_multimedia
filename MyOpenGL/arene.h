#ifndef ARENE_H
#define ARENE_H

#include "sphere.h"
#include "cercle_troue.h"
#include "math2.h"


class Arene
{
    Cercle_troue c;
public:
    Arene();
public slots:
    bool genererSphere();//renverra true si la sphere est generee et false sinon
    bool is_s_in_hole(Sphere &s);//condition
signals:
    void sphere_axee(Sphere &s);/*sera connecte a la generation d'une nouvelle sphere et plus tard a la fin de partie*/

};

#endif // ARENE_H
