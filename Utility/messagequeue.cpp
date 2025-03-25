#include "messagequeue.h"

#include <iostream>

template<typename T>
MessageQueue<T>::MessageQueue()
{

}

template<typename T>
void MessageQueue<T>::addMessage(T &msg)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_msgList.push_back(msg);
}


template<typename T>
void MessageQueue<T>::run()
{
    while (!isInterruptionRequested()) {
        std::unique_lock<std::mutex> lock(m_mutex);
        if(m_msgList.empty())
        {
            m_condition.wait(lock);
        }

        auto copy = m_msgList;
        for(auto msg : copy)
        {
            doMsg(msg);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}
