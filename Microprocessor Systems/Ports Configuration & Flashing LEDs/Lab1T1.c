/*
 * File:   Lab1T1.c
 * Author: Haashim Shahzada
 * Student ID: 500953004
 *
 * Created on September 28, 2021, 5:31 PM
 */

#include <p24FJ128GA010.h> //inclusion of pic24 library

void msDelay(int msec){ // msDelay() declaration
    int i,j;
    for(i=0;i<msec;i++){
        for(j=0;j<50;j++)
        {}
    }
}

int main (void){
   TRISA = 0; // initialize pins as output
   PORTAbits.RA0 = 0; // initialize pins as off
   PORTAbits.RA3 = 0; // initialize pins as off
   PORTAbits.RA4 = 0; // initialize pins as off
   while(1) {
      PORTAbits.RA0 = ~PORTAbits.RA0; //toggle value of RA0
      PORTAbits.RA3 = ~PORTAbits.RA3; //toggle value of RA3
      PORTAbits.RA4 = ~PORTAbits.RA4; //toggle value of RA4
      msDelay(1000); // delay of 1 second
   }
   return 0;
} 
