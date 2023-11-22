#pragma once

#include "driver/gpio.h"
#include "led.h"

class semafor
{
    private:
        Led green;
        Led yellow;
        Led red;
//   public:
//     enum class Connection
//     {
//         TO_GROUND,
//         TO_VCC
//     };

//   private:
//     gpio_num_t m_pin = GPIO_NUM_0;
//     Connection m_conn = Connection::TO_GROUND; 

//     static const char *TAG; 

//   public:
//     Led(gpio_num_t pin, Connection conn = Connection::TO_GROUND);
//     virtual ~Led();

  public:
    semafor(Led ledRed,Led ledYellow,Led ledGreen);
    semafor(Led ledRed,Led ledGreen);
    void carsGo();
    void carsGreen();
    void carsRed();
    void carsStop();
    
};