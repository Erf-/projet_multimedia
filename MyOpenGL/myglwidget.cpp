// myglwidget.cpp

#include "myglwidget.h"
#include "arene.h"

#include <gl/gl.h>
#include <GL/glu.h>
#include <windows.h>

#include "bras_robot.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    QObject::connect(this,SIGNAL(moved()),this,SLOT(draw()));
//    a = Arene();
//    Trou t = Trou(30,0.8,-1.2,1.2,0.0);
//    a.d_.setTrou(t);
//    a.d_.add(5);
//    d.setTexture(":/images/bois");
//    d.setTexture("C:/Users/Johanna/Desktop/multimedia/MyOpenGL/bois.tga");
}

void MyGLWidget::genSphere(int n){
    double x;//=rand(...);
    double y;//=rand(...);
    double z;//=rand(...);
    QObject::connect(this,SIGNAL(sphereGeneree(x,y,z))),this,SLOT(atteindre(x,y,y));
    //generation
    emit sphereGeneree(x,y,z);
}

void MyGLWidget::atteindre(double x, double y, double z, bool trou){
    double pas[3];//(finpos-pos)/nbimages
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(avancer(x,y,z,trou,pas)));
    timer->start(1000);
}

void MyGLWidget::avancer(double x, double y, double z, bool trou, double * pas){
    if(/*pos=!finpos*/){
        //pos+=pas;
        emit moved();
    }
    else{
        if(trou)
            emit trouAtteint();
        else
            emit sphereAtteinte(x,y,z);
    }
}

double * MyGLWidget::finalPos(double x, double y, double z){
    Vec u = Vec(x,y,z);
    double d = norm(u);
    double a = 1.2;
    double b = 1.6;
    u =u*(1/norm(u));
    double fintab[3]={acos((a*a+d*d-b*b)/(2*a*b)),acos((a*a+b*b-d*d)/(2*a*b)),angle(_X_,u)};
    return fintab;
}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

    glPointSize ( 1.0f );
    glLineWidth ( 1.0f );
    glPointSize (3);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable( GL_CULL_FACE );

//    GLtexture[0]=loadtgadisplayCDV("C:/Users/Johanna/Desktop/multimedia/MyOpenGL/bois.tga");
    GLtexture[0]=loadtgadisplayCDV("Z:/profile.V2/multimedia/MyOpenGL/bois.tga");
//    GLtexture[0]=loadtgadisplayCDV(":/images/bois.tga");
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // permet d'effacer les 2 buffer
    glLoadIdentity(); // permet de reinnitialiser les coor local vers les coor global
    /* glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);*/
    glRotatef(90, 1.0, 0.0, 0.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glTranslatef(-20, 0.0, 0.0); // on se met dans une bonne orientation pour voir l'objet (caméra et obj a la mm place)

    glRotatef(-xRot / 1.0, 0.0, 1.0, 0.0); // coor spérique téta
    glRotatef(-yRot / 1.0, 1.0, 0.0, 0.0); // phy
    glRotatef(-zRot / 1.0, 0.0, 0.0, 1.0); // doit etre lisse, pas saccadé pas trop rapide
    draw();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // glOrthof(-2, +2, -2, +2, 1.0, 15.0);
    gluPerspective(70,((float)width/(float)height), 0.01,30);
                   // angle, valeur corresp au ratio
                   // (determiné a partir de la taille de la fenetre), zmin et zmax

    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::draw()
{
//    glEnable(GL_TEXTURE_2D);

    glScaled(5.0,5.0,5.0);
    glColor3d(1.0,1.0,1.0);
//    glBindTexture(GL_TEXTURE_2D, GLtexture[0]);
    a.draw();
//    glDisable(GL_TEXTURE_2D);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glDisable( GL_CULL_FACE );
//    (new Bras_robot())->draw();
//    (new Sphere())->draw();
//    glCallList(box(0.4,0.4,0.2));
//    glCallList(cone(0.006,0.02));
}
