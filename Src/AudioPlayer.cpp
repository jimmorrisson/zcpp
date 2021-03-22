#include "AudioPlayer.hpp"

#include "Rectangular.hpp"
#include "Sawtooth.hpp"
#include "Sine.hpp"
#include "Subject.hpp"
extern "C"
{
#include "CS43L22.h"
    extern I2S_HandleTypeDef hi2s3;
    extern I2C_HandleTypeDef hi2c1;
}

AudioPlayer::AudioPlayer(Subject &subject, std::array<int16_t, 100> &&arr) : signal{std::make_unique<Sine>(std::move(arr))}
{
    subject.attach(this);
    CS43_Init(hi2c1, MODE_I2S);
    CS43_SetVolume(40); //0 - 100,, 40
    CS43_Enable_RightLeft(CS43_RIGHT_LEFT);
    CS43_Start();

    HAL_I2S_Transmit_DMA(&hi2s3, (uint16_t *)(signal->getData()), signal->getSampleN() * 2);
}

void AudioPlayer::update(int signal)
{
    std::array<int16_t, 100> data;
    switch (signal)
    {
    case 1:
    {
        this->signal = std::make_unique<Sine>(std::move(data));
        break;
    }
    case 2:
    {
        this->signal = std::make_unique<Rectangular>(std::move(data));
        break;
    }
    case 3:
    {
        this->signal = std::make_unique<Sawtooth>(std::move(data));
        break;
    }
    }

    HAL_I2S_DMAStop(&hi2s3);
    HAL_I2S_DeInit(&hi2s3);
    HAL_I2S_Init(&hi2s3);
    HAL_I2S_Transmit_DMA(&hi2s3, (uint16_t *)(this->signal->getData()), this->signal->getSampleN() * 2);
}
