#include "mainwindow.h"
#include "threaddemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int type = 1;
    int ret  = 0;
    switch ( type )
    {
    case 0:
    {
        MainWindow w;
        w.show();
        ret = a.exec();
    }
    break;
    case 1:
    {
        ThreadDemo w;
        w.show();
        ret = a.exec();
    }
    break;
    }

    return ret;
}
