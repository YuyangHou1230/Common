#include "windowresizehelper.h"

#include <QEvent>
#include <QWidget>
#include <QEnterEvent>
#include <QDebug>

WindowResizeHelper::WindowResizeHelper(QWidget *window) : QObject(nullptr)
{
    m_window = nullptr;
    m_Bound = Content_Bound;
    setTarget(window);
}

void WindowResizeHelper::setTarget(QWidget *window)
{
    if(m_window){
        m_window->removeEventFilter(this);
    }
    m_window = window;
    if(m_window){
        m_window->installEventFilter(this);
        m_window->setMouseTracking(true);
    }
}

bool WindowResizeHelper::eventFilter(QObject *obj, QEvent *e)
{
    if(obj != m_window){
        return false;
    }

    static Qt::CursorShape type = Qt::ArrowCursor;

    if(e->type() == QEvent::Enter){
        // 判断位置， 设置鼠标样式
        QEnterEvent *event = dynamic_cast<QEnterEvent*>(e);
        if(event){
            type = m_window->cursor().shape();

           Bound bound = calMouseBound(event->pos());

           setCursorShape(bound);
        }

    }
    else if(e->type() == QEvent::Leave) {
        m_window->setCursor(type);
    }
    else if(e->type() == QEvent::MouseMove) {
        qDebug() << "mouseMove";
        QMouseEvent *event = dynamic_cast<QMouseEvent*>(e);
        Bound bound = calMouseBound(event->pos());

        setCursorShape(bound);
    }
    else if(e->type() == QEvent::MouseButtonPress) {
        m_window->setCursor(type);
    }
    else if(e->type() == QEvent::MouseButtonRelease) {
        m_window->setCursor(type);
    }

    return false;
}

WindowResizeHelper::Bound WindowResizeHelper::calMouseBound(QPoint pos)
{
    Bound bound = Content_Bound;
    //左边界
    const int offset = 9;
    const int wid = 5;
    if(pos.x() <= wid && pos.y()  < m_window->height() - offset){
        bound =  Bound::Left_Bound;
    }


    else if(pos.x() >= m_window->width() - wid && pos.y()  < m_window->height() - offset){
        bound =  Bound::Right_Bound;
    }
    else if(pos.x() > offset && pos.x() < m_window->width() - offset && pos.y() > m_window->height() - wid){
        bound = Bottom_Bound;
    }
    else if(pos.x() <= offset && pos.y()  >= m_window->height() - offset){
        bound =  Bound::Left_Bottom_Bound;
    }
    else if(pos.x() >= m_window->width() - offset && pos.y()  >= m_window->height() - offset){
        bound =  Bound::Right_Bottom_Bound;
    }


    qDebug() << pos << bound << m_window->width() << m_window->height();

    return bound;
}

void WindowResizeHelper::setCursorShape(WindowResizeHelper::Bound bound)
{
    switch (bound) {
        case WindowResizeHelper::Content_Bound:
            m_window->setCursor(Qt::ArrowCursor);
            break;
        case WindowResizeHelper::Left_Bound:
        case WindowResizeHelper::Right_Bound:
            m_window->setCursor(Qt::SizeHorCursor);
            break;
        case WindowResizeHelper::Bottom_Bound:
            m_window->setCursor(Qt::SizeVerCursor);
            break;
        case WindowResizeHelper::Left_Bottom_Bound:
            m_window->setCursor(Qt::SizeBDiagCursor);
            break;
        case WindowResizeHelper::Right_Bottom_Bound:
            m_window->setCursor(Qt::SizeFDiagCursor);
            break;

    }
}


