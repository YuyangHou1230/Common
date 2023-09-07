#include "windowmovehelper.h"

#include <QEvent>
#include <QMouseEvent>
#include <QDebug>

WindowMoveHelper::WindowMoveHelper(QWidget *widget) : QObject(widget)
{
    // 顶层窗口检测
    Q_ASSERT_X(widget->isWindow(), "Error", "WindowMoveHelper can only be applied to widgets that are window type!");

    tartget = widget;
    widget->installEventFilter(this);
}

WindowMoveHelper::~WindowMoveHelper()
{
    if(tartget){
        tartget->installEventFilter(nullptr);
        tartget = nullptr;
    }
}

bool WindowMoveHelper::eventFilter(QObject *obj, QEvent *e)
{
    if(!tartget){
        return false;
    }
    static bool isPress = false;    // 鼠标是否按下
    static QPoint pressPos = QPoint(0, 0);   // 鼠标按下坐标
    static QPoint originPos = QPoint(0, 0);  // 鼠标按下时窗口位置

    if(obj == tartget){
        if(e->type() == QEvent::MouseButtonPress){
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent *>(e);
            if(mouseEvent && (mouseEvent->button() == Qt::LeftButton) ){
                isPress = true;
                pressPos = mouseEvent->globalPos();
                originPos = tartget->pos();

                qDebug() << "press" << pressPos << originPos;
            }
        }
        else if(e->type() == QEvent::MouseMove){
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent *>(e);
            if(mouseEvent  ){
                if(isPress){
                    QPoint newPos = originPos + mouseEvent->globalPos() - pressPos;
                    tartget->move(newPos);

                    qDebug() << "move" << newPos;
                }
            }
        }
        else if(e->type() == QEvent::MouseButtonRelease){
            QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent *>(e);
            if(mouseEvent && (mouseEvent->button() == Qt::LeftButton) ){
                isPress = false;
            }
        }
    }

    return false;
}
