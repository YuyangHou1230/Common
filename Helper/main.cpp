#include "widget.h"


#include "framelesswidget.h"
#include "ColorsSelect/colormenu.h"
#include "ColorsSelect/colorbutton.h"
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

//    FramelessWidget widget(lab);
//    ColorMenu widget;
    ColorButton widget;
    widget.show();

    return a.exec();
}
