#pragma once
#include "Button.hpp"
#include "Subject.hpp"
#include <list>

namespace sys
{
class SystemManager : public Subject
{
private:
    std::list<Observer *> observerList;
    int currentSignal = 0;
    void setSignal(int signal) noexcept;
    bool changeSignal(int signal) noexcept;

public:
    void handleSignalChanged(int signal);
    void attach(Observer *observer) override;
    void detach(Observer *observer) override;
    void notifyChange() override;

    static int translateButtonState(const bsp::Button::Signal signal);
};
} // namespace sys
