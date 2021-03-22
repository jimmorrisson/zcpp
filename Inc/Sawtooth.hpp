#pragma once
#include "Signal.hpp"
#include <math.h>

template <size_t size>
class Sawtooth : public Signal<size>
{
public:
    explicit constexpr Sawtooth(std::array<int16_t, size> &&data) : Signal<size>{std::move(data)}
    {
        auto b = -1.0;
        double d = 2.0 / this->sampleN;
        constexpr auto scaler = 8000;
        for (uint16_t i = 0; i < this->sampleN; i++)
        {
            if (i % this->sampleN)
            {
                b += 2.0;
            }
            const auto sawtoothValue = d * i - b;
            data.at(i * 2) = sawtoothValue * scaler;
            data.at(i * 2 + 1) = sawtoothValue * scaler;
        }
    }
};
