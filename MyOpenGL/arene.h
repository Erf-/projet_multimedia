#ifndef ARENE_H
#define ARENE_H

#include "sphere.h"
#include "math2.h"
#include "bras_robot.h"
#include "disque_troue.h"

using namespace math2;

class Arene
{
    Disque_troue d;
    Bras_robot b;
public:
    Arene();
private slots:
    void genererSphere();
public slots:
    bool genererNSpheres(int n){int i=0;for(i=0;i<n;i++) genererSphere(); return (i==n);}
    bool is_s_in_hole(Sphere &s);//condition
    void draw();
signals:
    void sphere_axee(Sphere &s);/*sera connecte a la generation d'une nouvelle sphere et plus tard a la fin de partie*/

};

#endif // ARENE_H
