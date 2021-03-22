#pragma once
#include "Signal.hpp"
#include <math.h>

class Rectangular : public Signal
{
public:
    explicit constexpr Rectangular(std::array<int16_t, arrSize> &&data) : Signal{std::move(data)}
    {
        constexpr auto maxValue = 8000;
        for (uint16_t i = 0; i < sampleN; i++)
        {
            if (i < (sampleN / 4))
            {
                data.at(i * 2) = maxValue;
                data.at(i * 2 + 1) = maxValue;
            }
            else if (i < ((sample / 4) * 3) && i >= ((sample / 4) * 2))
            {
                data.at(i * 2) = -maxValue;
                data.at(i * 2 + 1) = -maxValue;
            }
        }
    }
};
