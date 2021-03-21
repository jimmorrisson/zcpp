// #include "Button.h"

// namespace bsp
// {
// Button::Button(State state = State::Off) : state{state}, currentSignals{std::make_pair(Signal::Sine, Signal::Rectangle)}
// {
// }

// void Button::setState(GPIO_PinState gpioPinState)
// {
//     if (state == State::Off && gpioPinState == GPIO_PIN_SET)
//     {
//         state = State::On;
//         updateUpdateSingals();
//     }
//     else if (state == State::On && gpioPinState == GPIO_PIN_RESET)
//     {
//         state = State::Off;
//     }
// }

// std::pair<std::string, std::string> Button::getSingal() const
// {
//     const auto &[first, second] = currentSignals;
//     switch (first)
//     {
//     case Signal::Sine:
//     {
//         return {"Sinus", "Prostokat"};
//     }
//     case Signal::Rectangle:
//     {
//         return {"Sinus", "Prostokat"};
//     }
//     case Signal::Sawtooth:
//     {
//         return {"Sinus", "Prostokat"};
//     }
//     }
//     return {"", ""};
// }

// void Button::updateUpdateSingals() noexcept
// {
//     const auto &[first, second] = currentSignals;
//     switch (first)
//     {
//     case Signal::Sine:
//     {
//         currentSignals = std::make_pair(Signal::Rectangle, Signal::Sawtooth);
//         break;
//     }
//     case Signal::Rectangle:
//     {
//         currentSignals = std::make_pair(Signal::Sawtooth, Signal::Sine);
//         break;
//     }
//     case Signal::Sawtooth:
//     {
//         currentSignals = std::make_pair(Signal::Sine, Signal::Rectangle);
//         break;
//     }
//     }
// }
// } // namespace bsp
