#ifndef WINDOWMOVEHELPER_H
#define WINDOWMOVEHELPER_H

#include <QObject>
#include <QWidget>


/**
 * @brief The WindowMoveHelper class
 * 该类只能用于顶层窗口
 */
class WindowMoveHelper : public QObject
{
    Q_OBJECT
public:
    explicit WindowMoveHelper(QWidget *widget);
    virtual ~WindowMoveHelper();

signals:

protected:
    bool eventFilter(QObject *obj, QEvent *e) override;

    QWidget *tartget;

};

#endif // WINDOWMOVEHELPER_H
