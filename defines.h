/* 
 * File:   defines.h
 * Author: Zuois
 *
 * Created on February 4, 2016, 7:00 PM
 */

#ifndef DEFINES_H
#define	DEFINES_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum stateTypeEnum {
        stateLED1,
        statePressPauseLED1,
        statePressedLED1,
        stateUnPressPauseLED1,
        stateLED2,
        statePressPauseLED2,
        statePressedLED2,
        stateUnPressPauseLED2,
        stateLED3,
        statePressPauseLED3,
        statePressedLED3,
        stateUnPressPauseLED3
    } stateType;

    //Control variables
#define TRISOUTPUT 0
#define TRISINPUT 1
#define LATON 1
#define LATOFF 0
#define PRESCALAR_256 3
#define TIMERON 1;
#define TIMEROFF 0;

    //Board correlations
#define LED1 LATDbits.LATD0
#define LED1ENABLE TRISDbits.TRISD0
#define LED2 LATDbits.LATD1
#define LED2ENABLE TRISDbits.TRISD1
#define LED3 LATDbits.LATD2
#define LED3ENABLE TRISDbits.TRISD2


#ifdef	__cplusplus
}
#endif

#endif	/* DEFINES_H */

