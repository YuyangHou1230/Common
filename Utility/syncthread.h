#ifndef SYNCTHREAD_H
#define SYNCTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class Impl
{
public:
    virtual void startThread() = 0;
    virtual void stopThread() = 0;
    virtual void quitThread() = 0;
    virtual void runOnce() = 0;
    virtual void process() = 0;
};


class SyncThread : public Impl, public QThread
{
public:
    SyncThread();

    // Impl interface
public:
    void startThread();
    void stopThread();
    void quitThread();
    void runOnce();
    void process();

    // QThread interface
protected:
    void run();

private:
    bool m_isRun;

    QMutex m_lock;
    QWaitCondition m_waitCondition;
};

#endif // SYNCTHREAD_H
