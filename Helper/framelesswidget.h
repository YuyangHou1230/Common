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

signals:

protected:

    WindowMoveHelper *moveHelper;
};

#endif // FRAMELESSWIDGET_H
