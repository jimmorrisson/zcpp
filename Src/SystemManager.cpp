#include "SystemManager.hpp"
#include <utility>

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

int SystemManager::translateButtonState(int buttonPosition)
{
    return 1;
}
