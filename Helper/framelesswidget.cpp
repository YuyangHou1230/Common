#include "framelesswidget.h"

#include "windowmovehelper.h"

#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QLabel>

static const int ShadowWidth = 5;

FramelessWidget::FramelessWidget(QWidget *widget, QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);


    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(5, 5, 5, 5);

    QWidget *centraWidget = new QWidget();
    centraWidget->setObjectName("centraWidget");
    setStyleSheet("#centraWidget{background-color:rgb(51, 51, 51); border: 1px solid rgb(77, 77, 77); border-radius: 8px;}");

    mainLayout->addWidget(centraWidget);
    setLayout(mainLayout);


    QVBoxLayout *layout = new QVBoxLayout();

    QLabel *label = new QLabel("title");

//    layout->setContentsMargins(ShadowWidth, ShadowWidth, ShadowWidth, ShadowWidth);
    layout->addWidget(label);
    layout->addWidget(widget);


    centraWidget->setLayout(layout);

    //Qt窗口阴影类
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(widget);
    //设置阴影距离
    shadow->setOffset(0, 0);
    //设置阴影颜色  686868
    shadow->setColor(QColor(150, 150, 150));
    //设置阴影区域
    shadow->setBlurRadius(ShadowWidth);
    //给顶层QWidget设置阴影
//    centraWidget->setGraphicsEffect(shadow);

    moveHelper = new WindowMoveHelper(this);
}

FramelessWidget::~FramelessWidget()
{
    moveHelper->deleteLater();
}
