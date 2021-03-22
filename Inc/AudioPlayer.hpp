#pragma once
#include "Observer.hpp"
// #include "main.h"
#include "Signal.hpp"
#include <memory>

class Subject;

class AudioPlayer : public Observer
{
private:
    // const I2S_HandleTypeDef &i2sChannel;
    std::unique_ptr<Signal> signal;

public:
    explicit AudioPlayer(Subject &subject, std::array<int16_t, 100> &&arr);
    void update(int signal) override;
};
