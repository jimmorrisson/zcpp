#pragma once
#include <array>
#include <cstdint>

template <std::size_t size>
class Signal
{
protected:
    constexpr static auto sample = 48000.f;
    constexpr static auto out = 1500.f;
    constexpr static uint16_t sampleN = sample/out;
    constexpr static float sampleDt = out/sample;
    std::array<int16_t, size> data{};

public:
    virtual ~Signal() = default;

    [[nodiscard]] auto getData() const noexcept
    {
        return data.data();
    }

    [[nodiscard]] constexpr auto getSampleN() const noexcept
    {
        return sampleN;
    }
};
