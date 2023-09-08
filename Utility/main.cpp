#include "mainwindow.h"

#include <QApplication>

#include "singleapplication.h"

int main(int argc, char *argv[])
{
    SingleApplication a(argc, argv);
    if(a.isRunning()){
        a.doSomethingIfIsRun();
        return 0;
    }
    MainWindow w;
    a.setMainform(&w);
    w.show();
    return a.exec();
}
