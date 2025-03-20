#ifndef THREADDEMO_H
#define THREADDEMO_H

#include <QWidget>

#include "thread.h"

class SyncThread;

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

    void on_btnStart_2_clicked();

    void on_btnStop_2_clicked();

    void on_btnRun_clicked();

    void on_btnQuit_clicked();

private:
    Ui::ThreadDemo *ui;
    WorkerThread *  thread;
    SyncThread *m_syncThread;
};

#endif   // THREADDEMO_H
