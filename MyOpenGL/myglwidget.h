// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include <GL/glu.h>
#include <GL/gl.h>
#include "arene.h"
#include "math2.h"

using namespace math2;

class MyGLWidget : public QGLWidget
{
    Arene a;
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void avancer(double x, double y, double z, bool trou=false, double *pas);
    void atteindre(double x, double y, double z, bool trou=false);
    void genSphere(int n=1);
    double *finalPos(double x, double y, double z);

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
    // evenements de gestion du jeu
    void moved();
    void sphereGeneree(double x, double y, double z);
    void sphereAtteinte(double x, double y, double z);
    void trouAtteint();

private:
    void draw();

    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;
    GLuint GLtexture[1];
};

#endif // MYGLWIDGET_H

