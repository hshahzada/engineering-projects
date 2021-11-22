/*
 * File:   Lab7HS.c
 * Author: Haashim Shahzada
 * Student ID: 500953004
 *
 * Created on November 18, 2021, 7:20 PM
 */

// preprocessor directives
#include "xc.h"
#define USE_AND_OR
#include <p24FJ128GA010.h>
#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "adc.h"

// oscillator configuration
#pragma config POSCMOD = NONE
#pragma config FNOSC = FRC
#pragma config FCKSM = CSDCMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

#define _SUPPRESS_PLIB_WARNING
#define ADC_NSTEPS 1024

void ADCinit(void);
INT16 ADCread(void);
void sendBuffer(const char *buffer, UINT16 size);

void __attribute__((__interrupt__,auto_psv))_ADC1Interrupt(void)
{
    IFS0bits.AD1IF = 0;
}

int main(void) {
    INT16 ADCout;
    float f_ADCout;
    INT8 buff[ADC_NSTEPS];
    
    CloseUART2();
    U2MODE = 0x0008;
    OpenUART2(UART_EN, UART_TX_ENABLE, 25);
  
    T3CON = 0x8030;
    PR3 = 6249;
    
    TRISD = 0;
    TRISB = 0x0010;
    CNPU1 = 0x0000;

    AD1PCFG = 0xFFEF;
    ADCinit();
    
    while(1){
        ADCout = ADCread();
        f_ADCout = (5.0/ADC_NSTEPS)*(ADCout);
        LATD = ADCout >> 4;
        sprintf(buff, "\r\nAN4 is 0x%0X or %1.4fV:\r\n\r\n", ADCout, (double)f_ADCout);
        sendBuffer(buff, strlen(buff));
        while(TMR3);
    }
    CloseUART2();
}

void ADCinit(void){
    AD1CON2 = 0;
    AD1CHS = 0x0004;
    AD1CSSL = 0;
    AD1CON1 = 0x0000;
    AD1CON3 = 0x1F02;
    IFS0bits.AD1IF = 0;
    AD1CON1bits.ADON = 1;
}

INT16 ADCread(void){
    AD1CON1bits.SAMP = 1;
    while(TMR3);
    AD1CON1bits.SAMP = 0;
    while(!AD1CON1bits.DONE);
    return ADC1BUF0;
}

void sendBuffer(const char *buffer, UINT16 size){
    while(size){
        while(BusyUART2());
        WriteUART2(*buffer);
        buffer++;
        size--;
    }
}
