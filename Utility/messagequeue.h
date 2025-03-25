#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H


#include <QThread>
#include <vector>
#include <mutex>

template<typename T>
class MessageQueue : public QThread
{
public:
    MessageQueue();

    void addMessage(T &msg);

    virtual void doMsg(T &msg) = 0;


protected:
    void run() override;

   std::vector<T> m_msgList;
   std::mutex m_mutex;
   std::condition_variable m_condition;
};

#endif // MESSAGEQUEUE_H
