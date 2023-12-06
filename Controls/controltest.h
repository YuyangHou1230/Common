#ifndef CONTROLTEST_H
#define CONTROLTEST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ControlTest; }
QT_END_NAMESPACE

class ControlTest : public QMainWindow
{
    Q_OBJECT

public:
    ControlTest(QWidget *parent = nullptr);
    ~ControlTest();

private:
    Ui::ControlTest *ui;
};
#endif // CONTROLTEST_H
