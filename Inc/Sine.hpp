#pragma once
#include "Signal.hpp"
#include <cmath>

template <std::size_t size>
class Sine : public Signal<size>
{
public:
    constexpr Sine<size>() 
    {
        constexpr auto scaler = 8000;
        for (uint16_t i = 0; i < this->sampleN; i++)
        {
            const auto sinValue = sinf(i * 2 * M_PI * this->sampleDt);
            this->data.at(i * 2) = sinValue * scaler;
            this->data.at(i * 2 + 1) = sinValue * scaler;
        }
    }
};
