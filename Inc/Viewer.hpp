#pragma once
#include "Button.hpp"
#include <string_view>
#include <utility>
namespace view
{
    static constexpr std::pair<std::string_view, std::string_view> getSignals(const bsp::Button::Signal signal)
    {
        using Signal = bsp::Button::Signal;
        switch (signal)
        {
        case Signal::Sine:
            return {"Sine", "Rectangle"};
        case Signal::Rectangle:
            return {"Rectangle", "Sawtooth"};
        case Signal::Sawtooth:
            return {"Sawtooth", ""};
        }
        return {};
    }
    static constexpr std::pair<std::string_view, std::string_view> getSignals(const int state)
    {
        switch (state)
        {
        case 0:
            return {"Sine", "Rectangle"};
        case 1:
            return {"Rectangle", "Sawtooth"};
        case 2:
            return {"Sawtooth", ""};
        }
        return {};
    }

class Viewer
{
private:
public:
    
};
} // namespace view
