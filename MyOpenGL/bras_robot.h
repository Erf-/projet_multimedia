#ifndef BRAS_ROBOT_H
#define BRAS_ROBOT_H

#include "math2.h"
#include "sphere.h"
#include "cercle.h"

using namespace math2;

GLuint boule();
GLuint box(double lx, double ly, double depth);
GLuint cone(double base, double height);

class Bras_robot
{

public:
    /**
     * @brief x_
     * @brief y_
     * @brief z_
     * position du contact plateforme sphere epaule
     */
    double x_;
    double y_;
    double z_;
    /**
     * @brief alpha_
     * @brief beta_
     * @brief gamma_
     * rotations du bras
     */
    double alpha_;
    double beta_;
    double gamma_;

    Bras_robot(double x=0.0, double y=0.0, double z=0.0);
    void draw();
};

#endif // BRAS_ROBOT_H
