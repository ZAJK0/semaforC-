#pragma once
#include "driver/gpio.h"

class button
{
    private:
        gpio_num_t m_pin = GPIO_NUM_0;
    public:
        button(gpio_num_t pin);
        button();
        bool checkBut();
};