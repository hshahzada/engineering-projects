/*
 * File:   Lab6T1.c
 * Author: Haashim Shahzada
 *s
 * Created on November 9, 2021, 12:28 PM
 */

#include "xc.h"
#define USE_AND_OR
#include <p24FJ128GA010.h>
#include <uart.h>

#pragma config POSCMOD = NONE
#pragma config FNOSC = FRC
#pragma config FCKSM = CSDCMD
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

#define _SUPPRESS_PLIB_WARNING

void sendBuffer(const char *buffer, UINT16 size);
UINT8 getBuffer(char *buffer, UINT16 max);
UINT8 choice(void);

const char menu[] = 
{
"\r\n\r\nHere are the main menu choices\r\n"\
"Option 1. Display a Welcome Message\r\n"\
"Option 2. Turn On a LED\r\n"\
"Option 3. Display my Last Two ID Digits\r\n"\
"Option 4. UART echo\r\n"
"\r\nPlease Choose a number\r\n"
};

int main(void) {
    UINT8 menuoption;
    UINT8 buff[1024];
    CloseUART1();
    OpenUART1(UART_EN|UART_IDLE_CON|UART_NO_PAR_8BIT|UART_BRGH_SIXTEEN|UART_1STOPBIT,UART_TX_ENABLE, 25);
    CNPU1 = 0x0000;
    TRISB = 0xFFFF;
    TRISE = 0x0000;
    LATE = 0;
    sendBuffer(menu, sizeof(menu));
    while (1) {
        menuoption = choice();
        switch(menuoption){
            case 1:
                sprintf(buff, "\r\n Welcome to BME538 Fall 2021. I am Haashim Shahzada\r\n\r\n");
                    sendBuffer(buff, strlen(buff));
                    break;
            case 2:
                _RE9 = ~ _RE9;
                break;
            case 3:
                PORTE = PORTB;
                break;
            case 4:;
                UINT16 rx_size;
                sendBuffer("\r\nType a message and press enter \r\n", 
                        strlen("Type a message and press enter \r\n"));
                rx_size = getBuffer(buff, 1024);
                sendBuffer("\r\n\r\n", strlen("\r\n\r\n"));
                sendBuffer(buff, rx_size);
                break;
        }
        sendBuffer(menu, sizeof(menu));
    }
    CloseUART1();
    return 0;
}

void sendBuffer(const char *buffer, UINT16 size) {
    while(size){
        while(BusyUART1());
        WriteUART1(*buffer);
        buffer++;
        size--;
    }
}

UINT8 choice(void) {
    UINT8 number;
    while(!DataRdyUART1());
    number = ReadUART1();
    number -= '0';
    return number;
}

UINT8 getBuffer(char *buffer, UINT16 max) {
    UINT16 num;
    num = 0;
    while(num < max) {
        UINT8 letter;
        while(!DataRdyUART1());
        letter = ReadUART1();
        if(letter == '\r')
        break;
        *buffer = letter;
        buffer++;
        num++;
    }
    return num;
}