/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include "timer.h"
#include "defines.h"

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    TMR1 = 0;
    T1CONbits.TCKPS = PRESCALAR_256;
    PR1 = 39061;
    T1CONbits.ON = 1;
    IEC0bits.T1IE = 1;
    IPC1bits.T1IP = 7;
    IFS0bits.T1IF = 0;
}