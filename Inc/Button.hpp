#pragma once
#include "main.h"
#include "stm32f4xx_hal_gpio.h"
#include <string>

namespace bsp
{
class Button
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

    explicit Button(State state = State::Off) : state{state}, currentSignal{Signal::Sine}
    {
    }

    void setState(GPIO_PinState gpioPinState) noexcept;
    [[nodiscard]] Signal getSingal() const;

private:
    State state;
    Signal currentSignal;

    void updateUpdateSingals() noexcept;
};
} // namespace bsp
