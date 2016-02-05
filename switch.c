/* 
 * File:   switch.c
 * Author: Zuois
 *
 * Created on February 4, 2016, 9:57 PM
 */

#include <xc.h>
#include "switch.h"

void initSW1(){
    TRISDbits.TRISD6 = TRISINPUT;
    CNPUDbits.CNPUD6 = 1;
    CNCONDbits.ON = 1;
    CNENDbits.CNIED6 = 1;
    IFS1bits.CNDIF = 0;
    IEC1bits.CNDIE = 1;
    IPC8bits.CNIP = 7;
}

