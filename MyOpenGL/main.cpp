// main.cpp

#include <QApplication>
#include <QDesktopWidget>

#include "window.h"
#include "math2.h"

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

    return app.exec();
}
