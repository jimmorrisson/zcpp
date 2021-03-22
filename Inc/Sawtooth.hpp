#pragma once
#include "Signal.hpp"
#include <math.h>

class Sawtooth : public Signal
{
public:
    explicit constexpr Sawtooth(std::array<int16_t, arrSize> &&data) : Signal{std::move(data)}
    {
        auto b = -1.0;
        double d = 2.0 / sampleN;
        constexpr auto scaler = 8000;
        for (uint16_t i = 0; i < sampleN; i++)
        {
            if (i % sampleN)
            {
                b += 2.0;
            }
            const auto sawtoothValue = d * i - b;
            data.at(i * 2) = sawtoothValue * scaler;
            data.at(i * 2 + 1) = sawtoothValue * scaler;
        }
    }
};
