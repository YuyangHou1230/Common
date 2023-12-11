#include "widget.h"

#include "ColorsSelect/colorbutton.h"
#include "ColorsSelect/colormenu.h"
#include "framelesswidget.h"
#include "windowresizehelper.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    Widget w;
    //    w.show();

    //    QLabel *lab = new QLabel();
    //    lab->setMinimumSize(600, 400);
    //    lab->setText("1112");

    //    FramelessWidget widget(lab);
    //    WindowResizeHelper resize;
    //    resize.setTarget(widget.centralWidget());

    //    ColorMenu widget;
    ColorButton widget;
    widget.show();

    return a.exec();
}
