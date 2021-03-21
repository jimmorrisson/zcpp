#pragma once

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(int signal) = 0;
};