#include "SystemManager.hpp"
#include <utility>

namespace sys
{
void SystemManager::setSignal(int signal) noexcept
{
    if (const auto changed = changeSignal(signal); changed)
    {
        notifyChange();
    }
}

bool SystemManager::changeSignal(int signal) noexcept
{
    return std::exchange(currentSignal, signal) != signal;
}

void SystemManager::handleSignalChanged(int signal)
{
    setSignal(signal);
}

void SystemManager::attach(Observer *observer)
{
    observerList.push_back(observer);
}

void SystemManager::detach(Observer *observer)
{
    observerList.remove(observer);
}

void SystemManager::notifyChange()
{
    for (auto observer : observerList)
    {
        observer->update(currentSignal);
    }
}

int SystemManager::translateButtonState(const bsp::Button::Signal signal)
{
    using Signal = bsp::Button::Signal;
    switch (signal)
    {
    case Signal::Sine:
        return 0;
        break;
    case Signal::Rectangle:
        return 1;
        break;
    case Signal::Sawtooth:
        return 2;
        break;
    }
    return 0;
}
} // namespace sys
