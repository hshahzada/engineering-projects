/*
 * File:   Lab2Task.c
 * Author: Haashim Shahzada
 * Student ID: 500953004
 *
 * Created on October 5, 2021, 2:35 AM
 */

#include <p24Fxxxx.h>
#include "xc.h"

#define PB_PRESSED() (_RB4 == 0)
#define PB_RELEASED() (_RB4 == 1)
#define LED _RE0

void msDelay(int msec){ // msDelay() declaration
    int i,j;
    for(i=0;i<msec;i++){
        for(j=0;j<50;j++)
        {}
    }
}

typedef enum sw_state{
    STATE_RELEASED1,
    STATE_PRESSED1,
    STATE_RELEASED2,
    STATE_PRESSED2,
    STATE_RELEASED3,
    STATE_PRESSED3,   
    STATE_RELEASED4,
    STATE_PRESSED4,
};

void update_state(){
    static enum sw_state PBstate = STATE_RELEASED1;
    switch(PBstate){
        case STATE_RELEASED1:
	    LED = 1;
            if(PB_PRESSED()){ //PB_PRESSED == 0
                PBstate = STATE_PRESSED1;
            }
        break;
        case STATE_PRESSED1:
            if(PB_RELEASED()){//PB_RELEASED == 1
                LED = 0;
                PBstate = STATE_RELEASED2;
            }
        break;
        case STATE_RELEASED2:
            if(PB_PRESSED()){
                PBstate = STATE_PRESSED2;
            }
            break;
        case STATE_PRESSED2:
            if(PB_RELEASED()){
                LED = ~LED;
                msDelay(500);
                LED = ~LED;
                msDelay(500);
                LED = ~LED;
                msDelay(500);
                LED = ~LED;
                msDelay(500);
                PBstate = STATE_RELEASED3;
            }
            break;
        case STATE_RELEASED3:
            LED = 1;
            if(PB_PRESSED()){
                PBstate = STATE_PRESSED3;
            }
            break;
        case STATE_PRESSED3:
            if(PB_RELEASED() && PORTBbits.RB0 == 0){
                PBstate = STATE_RELEASED1;
            }
            if(PB_RELEASED() && PORTBbits.RB0 == 1){
                PBstate = STATE_RELEASED4;
            }
            break;
        case STATE_RELEASED4:
            if(PB_PRESSED()){
                while(PB_PRESSED()){
                    LED = ~LED;
                    msDelay(500);
                    LED = ~LED;
                    msDelay(500);
                }
                PBstate = STATE_PRESSED4;
            }
            break;
        case STATE_PRESSED4:
            if(PB_RELEASED()){
               PBstate = STATE_RELEASED1; 
            }
            break;
        default:
            break;
    }
}

int main(void) {
    AD1PCFG = 0xFFFF;
    CNPU1 = 0x0000;
    TRISB = 0b00010001;
    TRISE = 0;
    while(1){
       update_state();
    }
    return 0;
}
