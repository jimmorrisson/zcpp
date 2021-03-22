#pragma once
#include <array>
#include <stdint.h>

class Signal
{
protected:
    constexpr static auto arrSize = 100;
    constexpr static auto sample = 48000.f;
    constexpr static auto out = 1500.f;
    constexpr static uint16_t sampleN = sample/out;
    constexpr static float sampleDt = out/sample;
    std::array<int16_t, arrSize> data;

public:
    virtual ~Signal() = default;

    explicit constexpr Signal(std::array<int16_t, arrSize> &&data) : data{data}
    {
    }

    [[nodiscard]] auto getData() const noexcept
    {
        return data.data();
    }

    [[nodiscard]] constexpr auto getSampleN() const noexcept
    {
        return sampleN;
    }
};
