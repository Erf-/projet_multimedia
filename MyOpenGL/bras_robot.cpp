#include "bras_robot.h"

Bras_robot::Bras_robot(double x, double y, double z)
{
    x_=x;
    y_=y;
    z_=z;
}

/**
 * @brief cone
 * @param base
 * @param top
 * @param height
 * @return la display list du cone utilisee pour les doigts
 */
GLuint cone(double base, double height){

    GLuint dlcone=glGenLists(1);
    glNewList( dlcone, GL_COMPILE );

    GLUquadric *cone;
    cone=gluNewQuadric();
//    gluCylinder(cone,2,0,1,24,1);
    gluCylinder(cone,base,0,height,30,30);

    glEndList();

    return dlcone;
}

/**
 * @brief box
 * @param lx
 * @param ly
 * @param depth
 * @return
 */
GLuint box(double lx, double ly, double depth){

    GLuint dlbox=glGenLists(1);
    glNewList( dlbox, GL_COMPILE );

    glBegin(GL_QUADS);

    //face 1
    glTexCoord2d(1,0);
    glVertex3d(lx/2,ly/2,depth/2);
    glTexCoord2d(1,1);
    glVertex3d(lx/2,ly/2,-depth/2);
    glTexCoord2d(0,1);
    glVertex3d(-lx/2,ly/2,-depth/2);
    glTexCoord2d(0,0);
    glVertex3d(-lx/2,ly/2,depth/2);

    //face 2
    glTexCoord2d(1,0);
    glVertex3d(lx/2,-ly/2,depth/2);
    glTexCoord2d(1,1);
    glVertex3d(lx/2,-ly/2,-depth/2);
    glTexCoord2d(0,1);
    glVertex3d(lx/2,ly/2,-depth/2);
    glTexCoord2d(0,0);
    glVertex3d(lx/2,ly/2,depth/2);

    //face 3
    glTexCoord2d(1,0);
    glVertex3d(-lx/2,-ly/2,depth/2;
    glTexCoord2d(1,1);
    glVertex3d(-lx/2,-ly/2,-depth/2;
    glTexCoord2d(0,1);
    glVertex3d(lx/2,-ly/2,-depth/2;
    glTexCoord2d(0,0);
    glVertex3d(lx/2,-ly/2,depth/2;

    //face 4
    glTexCoord2d(1,0);
    glVertex3d(-lx/2,ly/2,depth/2;
    glTexCoord2d(1,1);
    glVertex3d(-lx/2,ly/2,-depth/2;
    glTexCoord2d(0,1);
    glVertex3d(-lx/2,-ly/2,-depth/2;
    glTexCoord2d(0,0);
    glVertex3d(-lx/2,-ly/2,depth/2;

    //face 5
    glVertex3d(lx/2,ly/2,-depth/2;
    glVertex3d(lx/2,-ly/2,-depth/2;
    glVertex3d(-lx/2,-ly/2,-depth/2;
    glVertex3d(-lx/2,ly/2,-depth/2;

    //face 6
    glVertex3d(lx/2,-ly/2,depth/2;
    glVertex3d(lx/2,ly/2,depth/2;
    glVertex3d(-lx/2,ly/2,depth/2;
    glVertex3d(-lx/2,-ly/2,depth/2;

    glEnd();

    glEndList();

    return dlbox;
}

/**
 * Display list pour générer une sphère.
 * Utile pour le bras robot.
 */
GLuint boule()
{
    GLuint boules=glGenLists(1);
    glNewList( boules, GL_COMPILE );

    GLUquadric *sphere;
    sphere=gluNewQuadric();
    gluSphere(sphere,0.2,45,45);

    glEndList();
    return boules;
}



void Bras_robot::draw(){

// socle
(new Cercle())->draw();

// epaule
glPushMatrix();

glColor3f(0.5,1,1);
glTranslatef(x_, y_, z_);
glRotated (gamma_,0,0,1); // angle sur le sol tourne autour de z
glRotated (alpha_,0,1,0);
(new Sphere(x_,y_,z_));//mettre le rayon a 0.4

// bras
glEnable(GL_TEXTURE_2D);

glPushMatrix();

glColor3f(1,1,1);
glTranslatef(0, 0, -0.6);
glCallList(box(0.1,0.1,0.4));

glDisable(GL_TEXTURE_2D);

// coude
glPushMatrix();

glColor3f(0.5,1,1);
glTranslatef(0, 0, -1.5);
glRotatef (beta_,0,1,0); // 2e °liberté: angle sur lequel on doit intervenir pour mettre en mouvement le bras robot.
(new Sphere(0, 0, 0));//rayon a 0.2

// avant bras
glEnable(GL_TEXTURE_2D);

glPushMatrix();

glColor3f(1,1,1);
glTranslatef(0, 0, -0.6);
glCallList(box(0.1,0.1,0.4));

glDisable(GL_TEXTURE_2D);

// poignet
glPushMatrix();

glColor3f(0.5,1,1);
glTranslatef(0, 0, -1.5);
glRotatef (-20,1,0,0);
(new Sphere(0, 0, 0));//rayon a 0.2

// doigts

// doigt 1 droit

glPushMatrix();

glColor3f (0.7, 0.7, 0.7);

glPushMatrix();

glRotatef (-35, 0, 1, 0);
glTranslatef (0, 0, -0.25);
glCallList(box(0.4,0.4,0.2));

glPopMatrix();

glPushMatrix();

glRotatef (-30, 0, 1, 0);
glTranslatef (0, 0, -0.4);
glRotatef (-120, 0, 1, 0); // angle pince
glCallList(cone(0.006,0.02));

glPopMatrix();

glPopMatrix();

//doigt 2 gauche
glPushMatrix();

glColor3f (0.7, 0.7, 0.7);

glPushMatrix();

glRotatef (35, 0, 1, 0);
glTranslatef (0, 0, -0.25);
glCallList(box(0.4,0.4,0.2));

glPopMatrix();

glPushMatrix();

glRotatef (30, 0, 1, 0);
glTranslatef (0, 0, -0.4);
glRotatef (120, 0, 1, 0); // angle pince
glCallList(cone(0.006,0.02));

glPopMatrix();

glPopMatrix();

glPopMatrix();

glPopMatrix();

glPopMatrix();

glPopMatrix();

}
