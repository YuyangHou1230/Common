#include "colorbutton.h"


#include <QHBoxLayout>
#include <QDebug>
ColorButton::ColorButton(QWidget *parent) : QFrame(parent)
{
    btnEdit = new QPushButton();
    btnEdit->setFixedSize(40, 40);

    colorLabel = new ColorIndicator();


    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(colorLabel, 1);
    layout->addWidget(btnEdit, 0);

    setLayout(layout);

     menu = new ColorMenu(this);
//     menu->hide();
     //     menu->
     connect(btnEdit, &QPushButton::clicked, this, [=](){
         //         QPoint pos = btnEdit->mapToParent(btnEdit->rect().bottomRight());
         QPoint pos = mapToGlobal(btnEdit->geometry().bottomRight());
         qDebug() << pos << btnEdit->geometry() << mapToGlobal(btnEdit->pos());
         menu->move(pos + QPoint(menu->geometry().topLeft() - menu->pos() ));
         qDebug() << menu->pos() << menu->frameGeometry();
         menu->exec();
     });
     connect(menu, &ColorMenu::selected, this, [=](QColor color){
         colorLabel->setColor(color);
         menu->accept();
     });
}
