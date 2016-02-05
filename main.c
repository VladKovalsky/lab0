/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "defines.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

//TODO: Use volatile variables that change within interrupts
volatile int state = 0;

int main() {
    SYSTEMConfigPerformance(10000000); //Configures low-level system parameters for 10 MHz clock
    enableInterrupts(); //This function is necessary to use interrupts.

    //TODO: Write each initialization function
    initLEDs();
    initTimer1();

    while (1) {

        //TODO: Implement a state machine to create the desired functionality
        switch (state) {
            case(stateLED0):
                LED0 = LATON;
                LED1 = LATOFF;
                LED2 = LATOFF;
                break;
            case(stateLED1):
                LED0 = LATOFF;
                LED1 = LATON;
                LED2 = LATOFF;
                break;
            case(stateLED2):
                LED0 = LATOFF;
                LED1 = LATOFF;
                LED2 = LATON;
                break;
        }


    }

    return 0;
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1INTERUPT() {
    IFS0bits.T1IF = 0;
    if (state == stateLED0) state = stateLED1;
    else if (state == stateLED1) state = stateLED2;
    else if (state == stateLED2) state = stateLED0;

}