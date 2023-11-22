#include "led.h"

#include "esp_log.h"

const char *Led::TAG = "LED";

Led::Led(gpio_num_t pin)
{
    m_pin = pin;

    ESP_LOGW(TAG, "Creation of class, pin: %d", m_pin);

    gpio_reset_pin(m_pin);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(m_pin, GPIO_MODE_INPUT_OUTPUT);
    
    off();
}

Led::~Led()
{
    ESP_LOGW(TAG, "Destroing of class, pin: %d", m_pin);
}
Led::Led(){
    m_pin = GPIO_NUM_0;
}

void Led::on()
{
    ESP_LOGD(TAG, "Switching to ON state, pin: %d", m_pin);
    gpio_set_level(m_pin, 1);
    
}

void Led::off()
{
    ESP_LOGD(TAG, "Switching to OFF state, pin: %d", m_pin);
    gpio_set_level(m_pin, 0);
   
}

void Led::toggle()
{
    if (gpio_get_level(m_pin) == 0)
    {
        gpio_set_level(m_pin, 1);
    }
    else
    {
        gpio_set_level(m_pin, 0);
    }
}
