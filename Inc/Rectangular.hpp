#pragma once
#include "Signal.hpp"
#include <cmath>

template <std::size_t size>
class Rectangular : public Signal<size>
{
public:
    constexpr Rectangular() 
    {
        constexpr auto maxValue = 8000;
        for (uint16_t i = 0; i < this->sampleN; i++)
        {
            if (i < (this->sampleN / 4))
            {
                this->data.at(i * 2) = maxValue;
                this->data.at(i * 2 + 1) = maxValue;
            }
            else if (i < ((this->sample / 4) * 3) && i >= ((this->sample / 4) * 2))
            {
                this->data.at(i * 2) = -maxValue;
                this->data.at(i * 2 + 1) = -maxValue;
            }
        }
    }
};
