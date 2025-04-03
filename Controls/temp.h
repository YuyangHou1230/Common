#ifndef TEMP_H
#define TEMP_H

#include <QPaintEvent>
#include <QWidget>

class Temp : public QWidget
{
    Q_OBJECT
public:
    explicit Temp(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *e);

private:
    int rotateTimer;
    int degree;
};

#endif // TEMP_H
