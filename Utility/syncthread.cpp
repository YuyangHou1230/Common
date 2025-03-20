#include "syncthread.h"

#include <QDebug>

SyncThread::SyncThread()
{
    m_isRun = false;
}

void SyncThread::startThread()
{
    if(!isRunning())
    {
        start();
        qDebug() << "start thread";
    }

    m_waitCondition.wakeAll();
    qDebug() << "start run";

}

void SyncThread::stopThread()
{

    m_lock.lock();
    m_isRun = false;
    m_waitCondition.wakeAll();
    m_lock.unlock();

    qDebug() << "stop run";
}

void SyncThread::quitThread()
{
    requestInterruption();
    m_lock.lock();
    m_waitCondition.wakeAll();
    m_lock.unlock();
}

void SyncThread::runOnce()
{
    qDebug() << "call thread:" << currentThreadId() << " call";
    m_lock.lock();
    m_waitCondition.wakeAll();
    m_lock.unlock();
}

void SyncThread::process()
{
    qDebug() << "process thread:" << currentThreadId() << " process";
}

void SyncThread::run()
{
    m_isRun = true;
    while (!isInterruptionRequested()) {

        m_lock.lock();
        m_waitCondition.wait(&m_lock);
        m_lock.unlock();

        if(m_isRun)
        {
            process();
        }
    }

    qDebug() << "thread quit";
}
