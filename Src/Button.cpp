#include "Button.hpp"

namespace bsp
{
void Button::setState(GPIO_PinState gpioPinState) noexcept
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

Button::Signal Button::getSingal() const
{
    return currentSignal;
}

void Button::updateUpdateSingals() noexcept
{
    const auto &signal = currentSignal;
    switch (signal)
    {
    case Signal::Sine:
    {
        currentSignal = Signal::Rectangle;
        break;
    }
    case Signal::Rectangle:
    {
        currentSignal = Signal::Sawtooth;
        break;
    }
    case Signal::Sawtooth:
    {
        currentSignal = Signal::Sine;
        break;
    }
    }
}
} // namespace bsp
