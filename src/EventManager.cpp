#include "EventManager.h"

#include <iostream>
#include <cassert>

EventManager::EventManager()
: m_activeQueue(0)
{

}

EventManager::~EventManager()
{

}

bool EventManager::AddListener(const EventListener& callback, const EventType& type)
{
    EventListenerList& listeners = m_eventListenerMap[type];

    for(auto it = listeners.begin(); it != listeners.end(); ++it)
    {
        if(callback == (*it))
        {
            std::cerr << "WARNING: Attempting to double-register a callback" << '\n';
            return false;
        }
    }
    listeners.push_back(callback);
    return true;
}

bool EventManager::RemoveListener(const EventListener& callback, const EventType& type)
{
    auto findIt = m_eventListenerMap.find(type);

    if(findIt != m_eventListenerMap.end())
    {
        EventListenerList& listeners = findIt->second;
        for(auto it = listeners.begin(); it != listeners.end(); ++it)
        {
            if(callback == (*it))
            {
                listeners.erase(it);
                return true;
            }
        }
    }
    return false;
}

bool EventManager::TriggerEvent(const IEventPtr& pEvent)
{
    auto findIt = m_eventListenerMap.find(pEvent->GetEventType());
    if(findIt != m_eventListenerMap.end())
    {
        EventListenerList& listeners = findIt->second;
        for(auto it = listeners.begin(); it != listeners.end(); ++it)
        {
            EventListener listener = (*it);
            listener(pEvent);
        }
    }
    return true;
}

bool EventManager::QueueEvent(const IEventPtr& pEvent)
{
    assert(m_activeQueue >= 0);
    assert(m_activeQueue < EVENTMANAGER_NUM_QUEUES);

    auto findIt = m_eventListenerMap.find(pEvent->GetEventType());
    if(findIt != m_eventListenerMap.end())
    {
        m_queues[m_activeQueue].push_back(pEvent);
        return true;
    }

    return false;
}

bool EventManager::Update()
{
    int curQueue = m_activeQueue;
    int nxtQueue = (m_activeQueue + 1) % EVENTMANAGER_NUM_QUEUES;
    m_activeQueue = nxtQueue;
    while(!m_queues[curQueue].empty())
    {
        IEventPtr pEvent = m_queues[curQueue].front();
        m_queues[curQueue].pop_front();
        TriggerEvent(pEvent);
    }
    return true;
}