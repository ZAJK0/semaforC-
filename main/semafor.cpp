#include "led.h"
#include "semafor.h"
#include "esp_log.h"



// const char *semafor::TAG = "SEMAFOR";
semafor::semafor(Led ledRed,Led ledYellow,Led ledGreen){
    red = ledRed;
    yellow = ledYellow;
    green = ledGreen;
};
semafor::semafor(Led ledRed,Led ledGreen){
    red = ledRed;
    green = ledGreen;
};
void semafor::carsGreen(){
    red.off();
    yellow.off();
    green.on();
}
void semafor::carsRed(){
    red.on();
    yellow.off();
    green.off();
}
void semafor::carsStop(){
    red.off();
    yellow.on();
    green.off();
}
void semafor::carsGo(){
    red.on();
    yellow.on();
    green.off();
}