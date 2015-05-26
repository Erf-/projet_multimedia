// main.cpp

#include <QApplication>
#include <QDesktopWidget>

#include "window.h"
#include "math2.h"
#include "arene.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    window.resize(window.sizeHint());
    int desktopArea = QApplication::desktop()->width() *
                     QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();

    window.setWindowTitle("OpenGL with Qt");

    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();

    //TESTS

    //Classe Vec
//    Vec a(1.0, 2.0, 0.0);
//    Vec b(2.0, 1.0, 0.0);
//    Vec c = a - b;
//    Vec d = a*3;
//    qDebug()<<a.x_<<" "<<a.y_<<" "<<a.z_;
//    qDebug()<<c.x_<<" "<<c.y_<<" "<<c.z_;
//    qDebug()<<d.x_<<" "<<d.y_<<" "<<d.z_;

    //Classe Cercle_troue
//    Cercle_troue c = Cercle_troue();
//    c.draw();
//    double tab[7];
//    tab[0]=rand_a_b(3,0,5)[0];
//    tab[1]=rand_a_b(3,0,5)[0];
//    tab[2]=rand_a_b(3,0,5)[1];
//    tab[3]=rand_a_b(3,0,5)[2];
//    tab[4]=rand_a_b(3,0,5)[3];
//    tab[5]=rand_a_b(3,0,5)[4];
//    tab[6]=rand_a_b(3,0,5)[0];
//    for(int i=0;i<7;i++)
//        qDebug()<<tab[i];

    return app.exec();
}
