// myglwidget.cpp

#include "myglwidget.h"
#include "arene.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    d = Disque_troue();
    Trou t = Trou(30,0.8,-1.2,1.2,0.0);
    d.setTrou(t);
    d.add(5);
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

GLuint loadtgadisplayCDV ( const char* filename )
{
    FILE* fp;
    char magic[12];
    unsigned char header[6];
    int imageSize;
    GLenum type;
    char temp;
    int i;
    int bpp,width,height;
    GLuint textureId;
    int globalWidth = 1;
    int globalHeight = 1;
    char* imageData;
    char* imageTmp;
    if(!(fp = fopen(filename, "rb"))) return 0;
    if(!fread(&magic, 12, 1, fp)) return 0;
    if(!fread(&header, 6, 1, fp)) return 0;
    bpp = header[4];
    width  = header[1] * 256 + header[0];
    height = header[3] * 256 + header[2];
    if(width <= 0 || height <= 0) return 0;
    if(bpp != 24 && bpp != 32) return 0;
    imageSize = width * height * (bpp / 8);
    imageData = (char *)malloc(sizeof(char) * imageSize);
    if(imageData == NULL) return 0;
    if(!fread(imageData, imageSize, 1, fp)) { free(imageData); return 0; }
    for(i = 0; i < imageSize; i += bpp / 8) {
    temp = imageData[i];
    imageData[i] = imageData[i + 2];
    imageData[i + 2] = temp; }
    if(bpp == 32) for(i=0;i<imageSize;i+=4) imageData[i+3]=255-imageData[i+3];
    fclose(fp);
    while (width>globalWidth) globalWidth*=2;
    while (height>globalHeight) globalHeight*=2;
    glEnable( GL_TEXTURE_2D );
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ROW_LENGTH,globalWidth);
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    if(bpp == 24) type=GL_RGB; else type=GL_RGBA;
    imageTmp = (char *)malloc(sizeof(char)*globalWidth*globalHeight*4);
    if (imageTmp==NULL) return 0;
    glTexImage2D(GL_TEXTURE_2D,0,type,globalWidth,globalHeight,0,
    type,GL_UNSIGNED_BYTE,imageTmp);
    free (imageTmp );
    glPixelStorei(GL_UNPACK_ROW_LENGTH,width);
    glTexSubImage2D(GL_TEXTURE_2D,0, 0,0, width, height,
    type ,GL_UNSIGNED_BYTE, imageData );
    free(imageData);
    return textureId;
}

void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLtexture[0]= loadtgadisplayCDV( "C:/Users/ghorbel/Downloads/MyOpenGL/rose.tga");


    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
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
    glRotatef(-yRot / 1.0, 0.0, 0.0, 1.0); // phy
    glRotatef(-zRot / 1.0, 1.0, 0.0, 0.0); // doit etre lisse, pas saccadé pas trop rapide
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
    //initialisation gl
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glEnable ( GL_NORMALIZE );
    glDepthMask ( GL_TRUE );
    glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
    glPointSize ( 1.0f );
    glLineWidth ( 1.0f );
    glEnable(GL_COLOR_MATERIAL);
    glPointSize (3);

    glEnable( GL_BLEND );
//    Trou t = Trou();
//    d.setTrou(t);
//    int k=0;
//    while(k<10){
//        d.add();
//        k++;
//    }
//    Cible c = Cible(30,0.5,-1.2,1.2,0.0);
//    glColor4fv(Rose);
//    c.draw();
//    d.add(c);
//    Cible c2 = Cible(30,0.5,1.2,-1.2,0.7);
//    d.add(c2);
//    c.draw();
//    c2.draw();
//    d.draw();
//    t.draw();
//    Arene a = Arene();
//    a.draw();
//    a.genererNSpheres(4);
//    glDepthMask (GL_FALSE);
//    glColor4fv(Rose);
//    (new Sphere())->draw();
//    (new Sphere(2.5))->draw();
//    (new Sphere(2.5,2.5))->draw();
//    glColor3f(3,1,2);
//    (new Cercle_troue(0.5,2.0,0.5,30.0,0.0,0.0,0.0,20))->draw();
//    (new Cercle_troue(30,1.0,3.0,1.5,30))->draw();
//    (new Disque_troue())->draw();
//    glDepthMask (GL_TRUE);
//    glDisable( GL_BLEND );
//    glEnable( GL_CULL_FACE );
//    glDisable( GL_TEXTURE_2D );
//    glEnable( GL_CULL_FACE );
}
