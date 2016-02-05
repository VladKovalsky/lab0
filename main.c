/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "defines.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

//TODO: Use volatile variables that change within interrupts
volatile int state = stateLED1;

int main() {
    SYSTEMConfigPerformance(10000000); //Configures low-level system parameters for 10 MHz clock
    enableInterrupts(); //This function is necessary to use interrupts.

    //TODO: Write each initialization function
    initLEDs();
    initTimer1();
    initTimer2();
    initSW1();

    while (1) {

        //TODO: Implement a state machine to create the desired functionality
        switch (state) {

            case(stateLED1):
                LED1 = LATON;
                LED2 = LATOFF;
                LED3 = LATOFF;
                break;
            case(statePressPauseLED1):
                if (T2CONbits.ON == 0) {
                    TMR2 = 0;
                    T2CONbits.ON = TIMERON;
                }
                break;
            case(statePressedLED1):
                if(PORTDbits.RD6 == 1){
                    state = stateUnPressPauseLED1;
                }
                break;
            case(stateUnPressPauseLED1):
                if (T2CONbits.ON == 0) {
                    TMR2 = 0;
                    T2CONbits.ON = TIMERON;
                }
                break;
            case(stateLED2):
                LED1 = LATOFF;
                LED2 = LATON;
                LED3 = LATOFF;
                break;
            case(statePressPauseLED2):
                if (T2CONbits.ON == 0) {
                    TMR2 = 0;
                    T2CONbits.ON = TIMERON;
                }
                break;
            case(statePressedLED2):
                if(PORTDbits.RD6 == 1){
                    state = stateUnPressPauseLED2;
                }
                break;
            case(stateUnPressPauseLED2):
                if (T2CONbits.ON == 0) {
                    TMR2 = 0;
                    T2CONbits.ON = TIMERON;
                }
                break;
            case(stateLED3):
                LED1 = LATOFF;
                LED2 = LATOFF;
                LED3 = LATON;
                break;
            case(statePressPauseLED3):
                if (T2CONbits.ON == 0) {
                    TMR2 = 0;
                    T2CONbits.ON = TIMERON;
                }
                break;
            case(statePressedLED3):
                if(PORTDbits.RD6 == 1){
                    state = stateUnPressPauseLED3;
                }
                break;
            case(stateUnPressPauseLED3):
                if (T2CONbits.ON == 0) {
                    TMR2 = 0;
                    T2CONbits.ON = TIMERON;
                }
                break;
        }


    }

    return 0;
}

//TODO: Add interrupt service routines that manage the change of states
//for particular events as needed

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNINTERUPT() {
    IFS1bits.CNDIF = 0;
    PORTD;
    if (state == stateLED1 && PORTDbits.RD6 == 0) {
        state = statePressPauseLED1;
    }
    else if (state == stateLED2 && PORTDbits.RD6 == 0) {
        state = statePressPauseLED2;
    }
    else if (state == stateLED3 && PORTDbits.RD6 == 0) {
        state = statePressPauseLED3;
    }
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1INTERUPT() {
    IFS0bits.T1IF = 0;
    T1CONbits.ON = TIMEROFF;
    if (state == statePressPauseLED1) {
        state = statePressedLED1;
    }
    else if (state == stateUnPressPauseLED1) {
        state = stateLED2;
    }
    else if (state == statePressPauseLED2) {
        state = statePressedLED2;
    }
    else if (state == stateUnPressPauseLED2) {
        state = stateLED3;
    }
    else if (state == statePressPauseLED3) {
        state = statePressedLED3;
    }
    else if (state == stateUnPressPauseLED3) {
        state = stateLED1;
    }
}

void __ISR(_TIMER_2_VECTOR, IPL7SRS) _T2INTERUPT() {
    IFS0bits.T2IF = 0;
    T2CONbits.ON = TIMEROFF;
    if (state == statePressPauseLED1) {
        state = statePressedLED1;
    }
    else if (state == stateUnPressPauseLED1) {
        state = stateLED2;
    }
    else if (state == statePressPauseLED2) {
        state = statePressedLED2;
    }
    else if (state == stateUnPressPauseLED2) {
        state = stateLED3;
    }
    else if (state == statePressPauseLED3) {
        state = statePressedLED3;
    }
    else if (state == stateUnPressPauseLED3) {
        state = stateLED1;
    }
}