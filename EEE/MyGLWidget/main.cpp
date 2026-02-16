
#include "myglwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyGLWidget w;   // ← nombre correcto de la clase
    w.resize(800, 600);  // opcional pero recomendable
    w.show();

    return a.exec();
}
