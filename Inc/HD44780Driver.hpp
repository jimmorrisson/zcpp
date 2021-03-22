#pragma once
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include <stdint.h>
#include <string>

namespace bsp
{
class HD44780Driver
{
private:
    void lcd_send_half_byte(uint8_t data);

public:
    void lcd_send_byte(uint8_t data);
    void lcd_write_cmd(uint8_t cmd);
    void lcd_init();
    void lcd_write_data(uint8_t data);
    void lcd_write_str(const char *text);
    void lcd_write_str(std::string &&text);
    void lcd_locate(uint8_t x, uint8_t y);
    void lcd_clear();
};
} // namespace bsp
