#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H


#include <QThread>
#include <queue>
#include <mutex>




template<typename T>
class MessageQueue : public QThread
{
public:
    MessageQueue()
    {

    }

    void start()
    {
        QThread::start();
    }
    void stop()
    {
        requestInterruption();
        wait();
    }

    typedef void (*Callback)(T msg);
    void addMessage(T msg)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_msgList.push(msg);
        m_condition.notify_one();
    }

    void setCallback(Callback call)
    {
        m_callback = call;
    };


protected:
    void run() override
    {
        while (!isInterruptionRequested()) {
            std::unique_lock<std::mutex> lock(m_mutex);
            if(m_msgList.empty())
            {
                m_condition.wait(lock);
            }

            auto copy = m_msgList;
            lock.unlock();

            m_mutex.lock();
            while (!m_msgList.empty())
            {
                T msg = m_msgList.front();
                m_msgList.pop();
                m_mutex.unlock();
                m_callback(msg);
                std::this_thread::sleep_for(std::chrono::milliseconds(10));

            }
        }
    }

   std::queue<T> m_msgList;
   std::mutex m_mutex;
   std::condition_variable m_condition;
   Callback m_callback;
};

#endif // MESSAGEQUEUE_H
