#pragma once
#include "Signal.hpp"
#include <math.h>

template <size_t size>
class Sine : public Signal<size>
{
public:
    explicit constexpr Sine(std::array<int16_t, size> &&data) : Signal<size>{std::move(data)}
    {
        constexpr auto scaler = 8000;
        for (uint16_t i = 0; i < this->sampleN; i++)
        {
            const auto sinValue = sinf(i * 2 * M_PI * this->sampleDt);
            data.at(i * 2) = sinValue * scaler;
            data.at(i * 2 + 1) = sinValue * scaler;
        }
    }
};
