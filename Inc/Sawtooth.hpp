#pragma once
#include "Signal.hpp"
#include <cmath>

template <std::size_t size>
class Sawtooth : public Signal<size>
{
public:
    constexpr Sawtooth<size>() 
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
            this->data.at(i * 2) = sawtoothValue * scaler;
            this->data.at(i * 2 + 1) = sawtoothValue * scaler;
        }
    }
};
