/*
 * File:   Lab6T2.c
 * Author: Haashim Shahzada
 *
 * Created on November 9, 2021, 12:28 PM
 */

#include "xc.h"
#define USE_AND_OR 

#include <p24FJ128GA010.h>
#include <uart.h>

#pragma POSCMOD = NONE 
#pragma config FNOSC = FRC 

void sendBuffer(const char *buffer, UINT16 size);
UINT16 rx_size; 

int main(void) {
    AD1PCFG = 0xFFFF;
    TRISB = 0xFF; 
    PORTB = 0;
    TRISE = 0x0000; 
    PORTE = 0;

    UINT8 buff[] = {
    33,33,33,34,34,34,34,34,34,35,37,39,41,42,42,41,40,38,37,36,35,34,32,31,31,31,31,30,31,31,
    32,33,34,33,31,28,27,29,34,45,63,89,122,154,177,182,163,127,84,46,23,16,18,23,25,25,24,23,
    24,24,24,24,23,24,25,26,27,28,28,28,29,29,30,30,31,31,32,32,33,33,34,35,36,38,39,39,41,42,
    43,44,46,47,48,49,50,52,52,53,54,55,55,55,55, 55,55,54,53,52,50,48,45,43,41,40,38,36,35,34,
    33,32,31,31,31,30,30,29,29,30,30,31,31,30,30,30,31,31,31,32,32,32,32,32,33,33,34,34,34,34,
    34,34,34,34,34};
    
    CloseUART1();
    U1MODE = 0x0008;
    OpenUART1(UART_EN|UART_IDLE_CON|UART_NO_PAR_8BIT|UART_BRGH_SIXTEEN|UART_1STOPBIT,UART_TX_ENABLE, 25);
    while(1){
        sendBuffer(buff, sizeof(buff));
    }   
    CloseUART1();
    return 0;
}

void sendBuffer(const char *buffer, UINT16 size) {
    while(size) {
        while(BusyUART1());
        WriteUART1(*buffer);
        buffer++;
        size--;
    }
}

