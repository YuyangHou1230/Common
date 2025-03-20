#include "threaddemo.h"
#include "ui_threaddemo.h"
#include "syncthread.h"

#include <QDebug>

ThreadDemo::ThreadDemo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ThreadDemo)
{
    ui->setupUi(this);

    thread = new WorkerThread();
    m_syncThread = new SyncThread();
}

ThreadDemo::~ThreadDemo()
{
    delete ui;
}

void ThreadDemo::on_btnStart_clicked()
{
    thread->start();
}

void ThreadDemo::on_btnPause_clicked()
{
    thread->pause();
}

void ThreadDemo::on_btnResume_clicked()
{
    thread->resume();
}

void ThreadDemo::on_btnStop_clicked()
{
    thread->stop();
}

void WorkerThread::process()
{
    qDebug() << "run";

    //    QThread::msleep(5);
}

void ThreadDemo::on_btnStart_2_clicked()
{
    m_syncThread->startThread();
}

void ThreadDemo::on_btnStop_2_clicked()
{
    m_syncThread->stopThread();
}

void ThreadDemo::on_btnRun_clicked()
{
    m_syncThread->runOnce();
}

void ThreadDemo::on_btnQuit_clicked()
{
    m_syncThread->quitThread();
}
