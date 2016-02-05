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
    
typedef enum stateTypeEnum{
    stateLED0 = 0,
    stateLED1 = 1,
    stateLED2 = 2
    
} stateType;

//Control variables
#define TRISOUTPUT 0
#define LATON 1
#define LATOFF 0
#define PRESCALAR_256 3

//Board correlations
#define LED0 LATDbits.LATD0
#define LED0ENABLE TRISDbits.TRISD0
#define LED1 LATDbits.LATD1
#define LED1ENABLE TRISDbits.TRISD1
#define LED2 LATDbits.LATD2
#define LED2ENABLE TRISDbits.TRISD2
    

#ifdef	__cplusplus
}
#endif

#endif	/* DEFINES_H */

