#include "controltest.h"
#include "loginform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    LoginForm    w;
    ControlTest w;
    w.show();
    return a.exec();
}
