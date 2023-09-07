#include "widget.h"


#include "framelesswidget.h"
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
//    w.show();



    QLabel *lab = new QLabel();
    lab->setMinimumSize(600, 400);
    lab->setText("1112");

    FramelessWidget *widget = new FramelessWidget(lab);
    widget->show();

    return a.exec();
}
