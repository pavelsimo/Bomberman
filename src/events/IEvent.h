#ifndef __IEVENT_H_
#define __IEVENT_H_

#include <ostream>

#include "EventType.h"
#include "../utility/FastDelegate.h"

class IEvent
{
    public:
        virtual const EventType& GetEventType() const = 0;
        virtual float GetTimeStamp() const = 0;
        virtual void Serialize(std::ostream& out) const = 0;
        virtual const std::string& GetName() const = 0;
};

#endif //__IEVENT_H_
