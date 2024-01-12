#include "threaddemo.h"
#include "ui_threaddemo.h"

#include <QDebug>

ThreadDemo::ThreadDemo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ThreadDemo)
{
    ui->setupUi(this);

    thread = new WorkerThread();
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

    //    QThread::msleep(20);
}
