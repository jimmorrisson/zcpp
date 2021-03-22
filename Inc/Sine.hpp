#pragma once
#include "Signal.hpp"
#include <math.h>

class Sine : public Signal
{
public:
    explicit constexpr Sine(std::array<int16_t, arrSize> &&data) : Signal{std::move(data)}
    {
        constexpr auto scaler = 8000;
        for (uint16_t i = 0; i < sampleN; i++)
        {
            const auto sinValue = sinf(i * 2 * M_PI * sampleDt);
            data.at(i * 2) = sinValue * scaler;
            data.at(i * 2 + 1) = sinValue * scaler;
        }
    }
};
