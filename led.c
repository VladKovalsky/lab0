/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"
#include "defines.h"

void initLEDs(){
    
    //TODO: Initialize LEDs
    LED0ENABLE = TRISOUTPUT;
    LED1ENABLE = TRISOUTPUT;
    LED2ENABLE = TRISOUTPUT;
    
    LED0 = LATOFF;
    LED1 = LATOFF;
    LED2 = LATOFF;
}

void turnOnLED(int led){
    
    //TODO: You may choose to write this function
    // as a matter of convenience
    
}