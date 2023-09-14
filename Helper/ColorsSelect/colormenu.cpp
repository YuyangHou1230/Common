#include "colormenu.h"

#include <QGridLayout>
#include <QRandomGenerator>
#include <QDebug>

ColorMenu::ColorMenu(QWidget *parent) : QDialog(parent)
{

    setWindowFlag(Qt::FramelessWindowHint);

    // 添先加4*4色块

    QGridLayout *layout = new QGridLayout();
    layout->setSpacing(0);

    for(int row=0; row < 4; row++){
        for(int column=0; column < 4; column++){
            int x= QRandomGenerator::global()->bounded(255);
            int y= QRandomGenerator::global()->bounded(255);
            int z= QRandomGenerator::global()->bounded(255);

            ColorBlock *block = new ColorBlock(QColor(x, y, z), this);
            block->setMinimumSize(40,40);
            layout->addWidget(block, row, column);
            m_blocks << block;

            connect(block, &ColorBlock::clicked, this, [=](){
                emit selected(block->color());

                qDebug() << "选中颜色：" << block->color();
            });
        }
    }

    setLayout(layout);
}
