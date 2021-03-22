#pragma once
#include "Observer.hpp"
#include "HD44780Driver.hpp"
class Subject;

class Display : public Observer
{
private:
    bsp::HD44780Driver driver;

public:
    explicit Display(Subject &subject);
    void update(int signal) override;
};
