#include "Display.hpp"
#include "Subject.hpp"
#include "Viewer.hpp"

Display::Display(Subject &subject)
{
    subject.attach(this);
    driver.lcd_init();
    driver.lcd_write_cmd(0x80);
    driver.lcd_write_data(0x3E);
    update(0);
}

void Display::update(int signal)
{
    driver.lcd_clear();
    const auto [first, second] = view::getSignals(signal);
    driver.lcd_locate(1, 0);
    driver.lcd_write_str(std::string{first});
    driver.lcd_locate(1, 1);
    driver.lcd_write_str(std::string{second});
}
