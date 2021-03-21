#pragma once
#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include "Observer.hpp"
#include "Subject.hpp"
#include <string>
#include <utility>

namespace bsp
{
class Button : public Observer
{
public:
    enum class State
    {
        On,
        Off
    };

    enum class Signal
    {
        Sine,
        Rectangle,
        Sawtooth
    };

    explicit Button(Subject &subject, State state = State::Off) : subject{subject}, state{state}, currentSignals{std::make_pair(Signal::Sine, Signal::Rectangle)}
    {
        subject.attach(this);
    }

    void setState(GPIO_PinState gpioPinState) noexcept
    {
        if (state == State::Off && gpioPinState == GPIO_PIN_SET)
        {
            state = State::On;
            updateUpdateSingals();
        }
        else if (state == State::On && gpioPinState == GPIO_PIN_RESET)
        {
            state = State::Off;
        }
    }
    [[nodiscard]] std::pair<std::string, std::string> getSingal() const
    {
        const auto &[first, second] = currentSignals;
        switch (first)
        {
        case Signal::Sine:
        {
            return {"Sinus", "Prostokat"};
        }
        case Signal::Rectangle:
        {
            return {"Prostokat", "Pila"};
        }
        case Signal::Sawtooth:
        {
            return {"Pila", ""};
        }
        }
        return {"", ""};
    }

    [[nodiscard]] int getButtonPosition()
    {
        return 1;
    }

private:
    Subject &subject;
    State state;
    std::pair<Signal, Signal> currentSignals;

    void update(int signal) override
    {
        int a = signal;
    }

    void updateUpdateSingals() noexcept
    {
        const auto &[first, second] = currentSignals;
        switch (first)
        {
        case Signal::Sine:
        {
            currentSignals = std::make_pair(Signal::Rectangle, Signal::Sawtooth);
            break;
        }
        case Signal::Rectangle:
        {
            currentSignals = std::make_pair(Signal::Sawtooth, Signal::Sine);
            break;
        }
        case Signal::Sawtooth:
        {
            currentSignals = std::make_pair(Signal::Sine, Signal::Rectangle);
            break;
        }
        }
    }
};
} // namespace bsp
