#ifndef THREAD_H
#define THREAD_H

#include <QMutex>
#include <QThread>
#include <QWaitCondition>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread(QObject *parent = nullptr);
    ~Thread() override;

    enum State
    {
        Stoped,    ///<停止状态，包括从未启动过和启动后被停止
        Running,   ///<运行状态
        Paused     ///<暂停状态
    };

    State state() const;

public slots:
    void start(Priority pri = InheritPriority);
    void stop();
    void pause();
    void resume();

protected:
    virtual void run() override final;
    virtual void process() = 0;

private:
    std::atomic_bool pauseFlag;   ///<暂停标识
    std::atomic_bool stopFlag;    ///<停止标识
    QMutex           mutex;       ///<锁，用于实现线程暂停
    QWaitCondition   condition;   ///<等待条件，用于实现线程暂停
};

#endif   // THREAD_H
