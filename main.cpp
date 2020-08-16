#include "testwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testWidget w;
    w.show();

    return a.exec();
}
