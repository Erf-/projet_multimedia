#ifndef ARENE_H
#define ARENE_H

#include "sphere.h"
#include "math2.h"
#include "bras_robot.h"
#include "disque_troue.h"
#include "paroi.h"

using namespace math2;

class Arene
{
    int nbs_;//nombre de spheres
public:
    Disque_troue d_;
    Paroi p_;
    Sphere spheres_[10];
    Bras_robot b_;
    bool move_;//
    Sphere ciblees_[10];
    double pas_[3];//

    Arene(int nb_points=30, double radius=1.5, double x=0.0, double y=0.0, double z=0.0);
//    bool genererNSpheres(int n){int i=0;for(i=0;i<n;i++) genererSphere(); return (i==n);}
    bool is_s_in_hole(Sphere &s);//condition
    void draw();
private slots:
    void genererSphere();    
signals:
    void sphere_ciblee();
    void sphere_axee();
    void moved();

};

#endif // ARENE_H
