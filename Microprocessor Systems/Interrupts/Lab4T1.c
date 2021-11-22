/*
 * File:   Lab4T1.c
 * Author: Haashim Shahzada
 * 500953004
 * Created on October 19, 2021, 11:46 PM
 */

#include "xc.h"
#pragma config FNOSC = FRC //4 mhz

void __attribute__((__interrupt__,no_auto_psv)) _T2Interrupt(void)
{
    _RA4=~_RA4;
    _T2IF=0;
}

void __attribute__((__interrupt__,no_auto_psv)) _T3Interrupt(void)
{
    _RA5=~_RA5;
    _T3IF=0;
}

int main(void) {
    TRISA = 0;
    LATA = 0;
    T2CON = 0x0030; // T2 OFF; 1:256 0.5 s delay time
    PR2 = 7811;
    _T2IP = 4;
    _T2IF = 0;
    _T2IE = 1;
    T3CON = 0x0030; // T3 OFF; 1:256 2 s delay time
    PR3 = 31249;
    _T3IP = 7;
    _T3IF = 0;
    _T3IE = 1;
    T2CONbits.TON = 1;
    T3CONbits.TON = 1;
    while(1){};
    return 0;
}