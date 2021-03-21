#pragma once
#include "Observer.hpp"

class Subject
{
    public:
    virtual ~Subject()= default;
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notifyChange() = 0;
};
