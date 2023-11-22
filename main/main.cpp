#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "led.h"
#include "button.h"
#include "semafor.h"
#include <memory>

static const char *TAG = "example";



static const gpio_num_t BLINK_GPIO_RED = GPIO_NUM_5;
static const gpio_num_t BLINK_GPIO_YELLOW = GPIO_NUM_4;
static const gpio_num_t BLINK_GPIO_GREEN = GPIO_NUM_18;
static const gpio_num_t BLINK_GPIO_GREEN2 = GPIO_NUM_27;
static const gpio_num_t BLINK_GPIO_RED2 = GPIO_NUM_26;
static const gpio_num_t BLINK_GPIO_BUTTON = GPIO_NUM_13;


extern "C"{
    char sem1State = 0; 
    bool butState = 0;
    Led redL(BLINK_GPIO_RED);
    Led yellowL(BLINK_GPIO_YELLOW);
    Led greenL(BLINK_GPIO_GREEN);
    Led green2(BLINK_GPIO_GREEN2);
    Led red2(BLINK_GPIO_RED2);
    button but1(BLINK_GPIO_BUTTON);
    semafor* sem1 = new semafor(redL,yellowL,greenL);
    semafor* sem2 = new semafor(red2,green2);
    void cars(void *arg){
        sem2->carsRed();
        while (1)
        {
            sem1->carsRed();
                vTaskDelay(pdMS_TO_TICKS(1000));
                sem1State = 1;
            if (butState == 1){
                sem2->carsGreen();
                vTaskDelay(pdMS_TO_TICKS(2000));
                sem2->carsRed();
                vTaskDelay(pdMS_TO_TICKS(2000));
                butState = 0;
            }      
            sem1->carsGo();
                vTaskDelay(pdMS_TO_TICKS(1000));
                sem1State = 2;
            sem1->carsGreen();
                vTaskDelay(pdMS_TO_TICKS(1000));
                sem1State = 3;
            sem1->carsStop();
                vTaskDelay(pdMS_TO_TICKS(1000));
                sem1State = 4;
        }
    }
    void watchBut(void *arg){
        while (1)
        {
            if (but1.checkBut()){
                butState = 1;
            }
        }
        
    }
    void app_main(void)
    {
        ESP_LOGI(TAG, "Start of main");

        esp_log_level_set("*", ESP_LOG_DEBUG);

        xTaskCreate(cars, "cars", 2048, NULL, 2, NULL);
        xTaskCreate(watchBut, "watchBut", 2048, NULL, 1, NULL);
    }
}
