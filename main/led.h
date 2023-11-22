#pragma once

#include "driver/gpio.h"

class Led
{
  public:
    Led();
    
  private:
    gpio_num_t m_pin = GPIO_NUM_0;

    static const char *TAG; 

  public:
    Led(gpio_num_t pin);
    virtual ~Led();

  public:
    void on();
    void off();
    void toggle();
};