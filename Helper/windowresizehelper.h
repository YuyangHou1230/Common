#ifndef WINDOWRESIZEHELPER_H
#define WINDOWRESIZEHELPER_H

#include <QObject>

class WindowResizeHelper : public QObject
{
    Q_OBJECT
public:
    enum Bound
    {
        Content_Bound,
        Left_Bound,
        Right_Bound,
        Bottom_Bound,
        Left_Bottom_Bound,
        Right_Bottom_Bound
    };

    explicit WindowResizeHelper(QWidget *window = nullptr);

    void setTarget(QWidget *window);

signals:

protected:
    bool eventFilter(QObject *obj, QEvent *e) override;

private:
    Bound calMouseBound(QPoint pos);
    void setCursorShape(Bound bound);

private:
    QWidget *m_window;
    Bound m_Bound;

};

#endif // WINDOWRESIZEHELPER_H
