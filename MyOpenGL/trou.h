#ifndef TROU_H
#define TROU_H

#include "cercle.h"
#include "math2.h"

using namespace math2;

class Trou : public Cercle
{
//    Disque_troue * d_;
public:

    Trou(int nb_points=30, double radius=1.0, double x=0.0, double y=0.0, double z=0.0);
//    void SetDisc(Disque_troue * d){d_=d;}
    //bool addVoisin(Trou t);
private:
};

#endif // TROU_H
