/*
 * File:   Lab1T2.c
 * Author: Haashim Shahzada
 * Student ID: 500953004
 *
 * Created on September 28, 2021, 5:31 PM
 */

#include <p24FJ128GA010.h>

void msDelay(int msec){
    int i,j;
    for(i=0;i<msec;i++){
        for(j=0;j<50;j++)
        {}
    }
}

void flash(int x) { // flash() declaration
   PORTAbits.RA0 = ~PORTAbits.RA0; // toggle pin RA0
   PORTAbits.RA3 = ~PORTAbits.RA3; // toggle pin RA3
   PORTAbits.RA4 = ~PORTAbits.RA4; // toggle pin RA4
   msDelay(x); // delay of x seconds
   PORTAbits.RA0 = ~PORTAbits.RA0; // toggle pin RA0
   PORTAbits.RA3 = ~PORTAbits.RA3; // toggle pin RA3
   PORTAbits.RA4 = ~PORTAbits.RA4; // toggle pin RA4
   msDelay(x); // delay of x seconds
}

int main (void){
   TRISA = 0; // initialize pins as output
   PORTAbits.RA0 = 0; // initialize pins as off
   PORTAbits.RA3 = 0; // initialize pins as off
   PORTAbits.RA4 = 0; // initialize pins as off
   while(1) { //forever while loop
      flash(500); //long flash
      flash(250); //short flash
      msDelay(3000); // delay of 3 seconds
      flash(500); //long flash
      flash(250); //short flash
      flash(250); //short flash
      flash(250); //short flash
      msDelay(3000); // delay of 3 seconds
      flash(500); //long flash
      flash(250); //short flash
      flash(500); //long flash
      flash(250); //short flash
      msDelay(3000); // delay of 3 seconds
   }
   return 0;
}   
