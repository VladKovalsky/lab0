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
    LED1ENABLE = TRISOUTPUT;
    LED2ENABLE = TRISOUTPUT;
    LED3ENABLE = TRISOUTPUT;
    
    LED1 = LATOFF;
    LED2 = LATOFF;
    LED3 = LATOFF;
}

void turnOnLED(int led){
    
    //TODO: You may choose to write this function
    // as a matter of convenience
    
}