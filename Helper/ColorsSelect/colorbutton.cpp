#include "colorbutton.h"


#include <QHBoxLayout>
#include <QDebug>
ColorButton::ColorButton(QWidget *parent) : QFrame(parent)
{
    btnEdit = new QPushButton();
    btnEdit->setFixedSize(40, 40);

    colorLabel = new ColorIndicator();


    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(6, 6, 6, 6);
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


         // 移动到正下方显示
         menu->resize(width(), width());
         menu->move( mapToGlobal(QPoint(0, height())));


         menu->exec();
     });
     connect(menu, &ColorMenu::selected, this, [=](QColor color){
         colorLabel->setColor(color);
         menu->accept();
     });

}
