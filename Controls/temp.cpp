#include "temp.h"

#include <QPainter>
#include <QDebug>

Temp::Temp(QWidget *parent) : QWidget(parent)
{
    rotateTimer = startTimer(1000);
    degree = 0;
}

void Temp::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    painter.fillRect(rect(), Qt::gray);

    painter.translate(QPoint(width() / 2, height() / 2));

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));

    int r = qMin(width(), height()) / 2 - 10;

    painter.save();
    for(int i = 0; i < 60; i++)
    {
        painter.rotate( double(6) );
//        painter.fillRect(QRect( -80, -80, 160, 160), Qt::green);
        painter.drawLine(QPoint(r, 0), QPoint(r + 3, 0));
    }

    painter.restore();

    painter.rotate(degree);
     // 画指针
    QPainterPath path;
    QPolygon points;
    points << QPoint(0, -3)
           << QPoint(0, 3)
           << QPoint(r-8, 3)
           << QPoint(r-3, 0)
           << QPoint(r-8, -3) ;
    path.addPolygon(points);
    path.closeSubpath();

    painter.fillPath(path, Qt::green);

//    painter.restore();

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawEllipse(QRect(-5, -5, 10, 10));
}

void Temp::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == rotateTimer)
    {
        degree += 6 ;
        degree = degree % 360;

//        qDebug() << degree;
        update();
    }
}
