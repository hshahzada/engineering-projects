/*
 * File:   Lab5HS.c
 * Author: Haashim Shahzada
 * Student ID: 500953004
 *
 * Created on November 2, 2021, 5:37 PM
 */

#include "xc.h"
#include <outcompare.h>
#pragma config FCKSM = CSDCMD
#pragma config FNOSC = FRCPLL
#pragma config POSCMOD = NONE 
#pragma config JTAGEN = OFF
#pragma config FWDTEN = OFF
#define RSV 9999 // Random arbritary value set. 

// Remove comments for each duty cycle.
int dcycle = (RSV+1)*((double)20/100); // duty cycle of 20%
//int dcycle = (RSV+1)*((double)60/100); // duty cycle of 60%
//int dcycle = (RSV+1)*((double)90/100); // duty cycle of 90%

void __attribute__ ((__interrupt__, auto_psv)) _ISR _T2Interrupt (void){
    OC4RS = dcycle;
    _T2IF = 0;
}

void configOutputCompare1(void){
    T2CONbits.TON = 0;
    OC4R = 1600/2;
    OC4CON = 0x0003;
    _OC4IF = 0;
    _OC4IP = 1;
    _OC4IE = 1;
}

int main (void) {
   OC4CON = 1;
   OC4R = 1600;
   OC4CONbits.OCTSEL = 1;
   OC4CON = 0x0006;
   //T2CONbits.TON = 0;
   TRISDbits.TRISD3 = 0;
   LATD = 0;
   PR2 = RSV;
   T2CON = 0x8000;
   _T2IP = 4;
   _T2IF = 0;
   _T2IE = 1;
   //configOutputCompare1();
   //T2CONbits.TON = 1;
   while(1){};
   return 0;
}
