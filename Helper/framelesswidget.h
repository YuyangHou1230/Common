#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>

class WindowMoveHelper;

class FramelessWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FramelessWidget(QWidget *widget, QWidget *parent = nullptr);
    ~FramelessWidget();

    QWidget *centralWidget();

signals:

protected:

    WindowMoveHelper *moveHelper;
    QWidget *centraWidget;
};

#endif // FRAMELESSWIDGET_H
