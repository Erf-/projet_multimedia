#ifndef CERCLE_H
#define CERCLE_H

class Cercle
{
public:
    GLfloat (*points_)[3];
    GLdouble x_;
    GLdouble y_;
    GLdouble z_;
    int nb_points_;
    GLdouble radius_;

    Cercle(int nb_points_=30, double radius_=3.0, double x_=0.0, double y_=0.0, double z_=0.0);
private slots:
    bool calcul();
public slots:
    void draw();
};

#endif // CERCLE_H
