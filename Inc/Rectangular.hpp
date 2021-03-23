#pragma once
#include "Signal.hpp"
#include <math.h>

template <std::size_t size>
class Rectangular : public Signal<size>
{
public:
    explicit constexpr Rectangular(std::array<int16_t, size> &&data) : Signal<size>{std::move(data)}
    {
        constexpr auto maxValue = 8000;
        for (uint16_t i = 0; i < this->sampleN; i++)
        {
            if (i < (this->sampleN / 4))
            {
                data.at(i * 2) = maxValue;
                data.at(i * 2 + 1) = maxValue;
            }
            else if (i < ((this->sample / 4) * 3) && i >= ((this->sample / 4) * 2))
            {
                data.at(i * 2) = -maxValue;
                data.at(i * 2 + 1) = -maxValue;
            }
        }
    }
};
