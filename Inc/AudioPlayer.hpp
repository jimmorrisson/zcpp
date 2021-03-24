#pragma once

#include "Observer.hpp"
#include "Rectangular.hpp"
#include "Sawtooth.hpp"
#include "Signal.hpp"
#include "Sine.hpp"
#include "Subject.hpp"

#include <memory>

extern "C"
{
#include "CS43L22.h"
    extern I2S_HandleTypeDef hi2s3;
    extern I2C_HandleTypeDef hi2c1;
}

namespace audio
{
template <std::size_t size>
class AudioPlayer : public Observer
{
private:
    std::unique_ptr<Signal<size>> signal;

public:
    explicit AudioPlayer(Subject &subject) : signal{std::make_unique<Sine<size>>()}
    {
        subject.attach(this);
        CS43_Init(hi2c1, MODE_I2S);
        CS43_SetVolume(40);
        CS43_Enable_RightLeft(CS43_RIGHT_LEFT);
        CS43_Start();

        HAL_I2S_DMAStop(&hi2s3);
        HAL_I2S_DeInit(&hi2s3);
        HAL_I2S_Init(&hi2s3);
        HAL_I2S_Transmit_DMA(&hi2s3, (uint16_t *)(signal->getData()), signal->getSampleN() * 2);
    }
    void update(int signal) override
    {
        switch (signal)
        {
        case 1:
        {
            this->signal = std::make_unique<Sine<size>>();
            break;
        }
        case 2:
        {
            this->signal = std::make_unique<Rectangular<size>>();
            break;
        }
        case 3:
        {
            this->signal = std::make_unique<Sawtooth<size>>();
            break;
        }
        }

        HAL_I2S_DMAStop(&hi2s3);
        HAL_I2S_DeInit(&hi2s3);
        HAL_I2S_Init(&hi2s3);
        HAL_I2S_Transmit_DMA(&hi2s3, (uint16_t *)(this->signal->getData()), this->signal->getSampleN() * 2);
    }
};
} // namespace audio
