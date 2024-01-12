#ifndef THREADDEMO_H
#define THREADDEMO_H

#include <QWidget>

#include "thread.h"

class WorkerThread : public Thread
{
protected:
    void process() override;
};

namespace Ui
{
class ThreadDemo;
}

class ThreadDemo : public QWidget
{
    Q_OBJECT

public:
    explicit ThreadDemo(QWidget *parent = nullptr);
    ~ThreadDemo();

private slots:
    void on_btnStart_clicked();

    void on_btnPause_clicked();

    void on_btnResume_clicked();

    void on_btnStop_clicked();

private:
    Ui::ThreadDemo *ui;
    WorkerThread *  thread;
};

#endif   // THREADDEMO_H
