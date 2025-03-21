#include "animationlyriclist.h"


#include <QResizeEvent>
#include <QSequentialAnimationGroup>
#include <QTimer>
#include <QDebug>

AnimationLyricList::AnimationLyricList(QWidget *parent) : QWidget(parent)
{
    // 创建顺序动画组
    m_animationGrop = new QParallelAnimationGroup ();

    for(int i=0; i < 50; i++)
    {
        QLabel *label = new QLabel(QString("歌词行%1").arg(i+1), this);
        label->setAlignment(Qt::AlignCenter);
        QPropertyAnimation *animation1 = new QPropertyAnimation(label, "geometry");
        animation1->setDuration(400);
        LyricItem *item = new LyricItem(label, animation1);
        m_items.append(item);

        // 将动画添加到顺序动画组
        m_animationGrop->addAnimation(animation1);
    }

    setMinimumSize(400,300);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=](){
            m_index +=1;
        animationToLine(0);
    });

    timer->start(1000);
}

void AnimationLyricList::loadList(QStringList list)
{
    m_list = list;
}


void AnimationLyricList::animationToLine(int index)
{
    if(m_index >= 50)
    {
        return;
    }

    index = m_index;
    int h = height() / 9;
    for(int i=0; i < 50; i++)
    {
        // 为每个 QLabel 创建 QPropertyAnimation
        QRect rect = m_items[i]->label->geometry();
        m_items[i]->animation->setStartValue(rect);
        QRect end = QRect(rect.x(), (9 / 2 )*h + (i - index) * h, rect.width(), rect.height());
        m_items[i]->animation->setEndValue(end);

        if(i == m_index)
        {
            m_items[i]->label->setStyleSheet("background: rgb(135,206,250);");
        }
        else
        {
            m_items[i]->label->setStyleSheet("background: transparent;");
        }

        if(i == 0)
        {
//            qDebug() << "start" << rect << "end:" << end;
        }
//        m_items[i]->animation->setDuration(500);
    }


    // 启动所有动画
    m_animationGrop->start();

}

void AnimationLyricList::recalculate(QSize size)
{
    int index = 12;
    int height = size.height() / 9;
    for(int i=0; i < 50; i++)
    {
        m_items[i]->label->setGeometry( 0, (9 / 2 )*height + (i - m_index) * height, size.width(), height);
        if(i == m_index)
        {
            m_items[i]->label->setStyleSheet("background: rgb(135,206,250);");
        }
        else
        {
            m_items[i]->label->setStyleSheet("background: transparent;");
        }
    }
}

void AnimationLyricList::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    recalculate(event->size());
}
