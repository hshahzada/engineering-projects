/*
 * File:   Lab4T2.c
 * Author: Haashim Shahzada
 * 500953004
 * Created on October 20, 2021, 10:38 AM
 */

#include "xc.h"
#pragma config FNOSC = FRC //4 mhz

void __attribute__((__interrupt__,no_auto_psv)) _INT1Interrupt(void)
{
    while(_RE8 == 0){
        _RD2=0;
        _RD1=1;
        _RD0=1;
    }
    _INT1IF=0;
    _RD2 = 1;
    _RD1 = 0;
    _RD0 = 0;  
}

int main(void) {
    // Part 2
    _T2IE = 0;
    _T3IE = 0;
    _INT1EP = 1;
    _INT1IF = 0;
    _INT1IP = 1;
    _INT1IE = 1;
    
    TRISD = 0x00;
    TRISE = 0b0000001111111111;
    LATD = 0b00000100;
    while(1){};
    return 0;
}