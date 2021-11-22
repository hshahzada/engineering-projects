/* File:   Lab3HS.c
 * Author: Haashim Shahzada (500953004)
 * BME 538 Section 2
 * Created on October 10, 2021, 2:49 PM
 */
#include "xc.h"
#include "p24FJ128GA010.h"

int keyNumR = 99;
int keyNumL = 99;

void msDelay(int msec){
    int i,j;
    for(i=0;i<msec;i++){
        for(j=0;j<50;j++)
        {}
    }
}

void disp1(){
    keyNumR = ReadKeypad();
    if (keyNumR == 0) {
        _RD0 = 0;
        _RD1 = 0;
        _RD2 = 0;
        _RD3 = 0;
    }
    else if (keyNumR == 1) {
        _RD0 = 1;
        _RD1 = 0;
        _RD2 = 0;
        _RD3 = 0;
    }
    else if (keyNumR == 2) {
        _RD0 = 0;
        _RD1 = 1;
        _RD2 = 0;
        _RD3 = 0;
    }
    else if (keyNumR == 3) {
        _RD0 = 1;
        _RD1 = 1;
        _RD2 = 0;
        _RD3 = 0;
    }
    else if (keyNumR == 4) {
        _RD0 = 0;
        _RD1 = 0;
        _RD2 = 1;
        _RD3 = 0;
    }
    else if (keyNumR == 5) {
        _RD0 = 1;
        _RD1 = 0;
        _RD2 = 1;
        _RD3 = 0;
    }
    else if (keyNumR == 6) {
        _RD0 = 0;
        _RD1 = 1;
        _RD2 = 1;
        _RD3 = 0;
    }
    else if (keyNumR == 7) {
        _RD0 = 1;
        _RD1 = 1;
        _RD2 = 1;
        _RD3 = 0;
    }
    else if (keyNumR == 8) {
        _RD0 = 0;
        _RD1 = 0;
        _RD2 = 0;
        _RD3 = 1;
    }
    else if (keyNumR == 9) {
        _RD0 = 1;
        _RD1 = 0;
        _RD2 = 0;
        _RD3 = 1;
    }
}

void disp2(){
    keyNumL = ReadKeypad();
    if (keyNumL == 0) {
        _RD4 = 0;
        _RD5 = 0;
        _RD6 = 0;
        _RD7 = 0;
    }
    else if (keyNumL == 1) {
        _RD4 = 1;
        _RD5 = 0;
        _RD6 = 0;
        _RD7 = 0;
    }
    else if (keyNumL == 2) {
        _RD4 = 0;
        _RD5 = 1;
        _RD6 = 0;
        _RD7 = 0;
    }
    else if (keyNumL == 3) {
        _RD4 = 1;
        _RD5 = 1;
        _RD6 = 0;
        _RD7 = 0;
    }
    else if (keyNumL == 4) {
        _RD4 = 0;
        _RD5 = 0;
        _RD6 = 1;
        _RD7 = 0;
    }
    else if (keyNumL == 5) {
        _RD4 = 1;
        _RD5 = 0;
        _RD6 = 1;
        _RD7 = 0;
    }
    else if (keyNumL == 6) {
        _RD4 = 0;
        _RD5 = 1;
        _RD6 = 1;
        _RD7 = 0;
    }
    else if (keyNumL == 7) {
        _RD4 = 1;
        _RD5 = 1;
        _RD6 = 1;
        _RD7 = 0;
    }
    else if (keyNumL == 8) {
        _RD4 = 0;
        _RD5 = 0;
        _RD6 = 0;
        _RD7 = 1;
    }
    else if (keyNumL == 9) {
        _RD4 = 1;
        _RD5 = 0;
        _RD6 = 0;
        _RD7 = 1;
    }
}

int ReadKeypad() {
    
    int row = 0;
    int col = 0;
    
    if (_RB2 == 0) {
        row = 1;
    }
    else if (_RB3 == 0) {
        row = 2;
    } else if (_RB4 == 0) {
        row = 3;
    } else if (_RB5 == 0) {
        row = 4;
    } else {
        row = 5;
    };
    
    if (row != 5) {
        LATE = 0b01100000;
        if (_RB2 == 0) {
            col = 1;
        } else if (_RB3 == 0) {
            col = 1;
        } else if (_RB4 == 0) {
            col = 1;
        } else if (_RB5 == 0) {
            col = 1;
        } else {
            col = 5;
        };
        
        if (col == 5) {
            LATE = 0b01010000;
            if (_RB2 == 0) {
                col = 2;
            } else if (_RB3 == 0) {
                col = 2;
            } else if (_RB4 == 0) {
                col = 2;
            } else if (_RB5 == 0) {
                col = 2;
            } else {
                col = 5;
            };           
        };
        
        if (col == 5) {
            LATE = 0b00110000;
            if (_RB2 == 0) {
                col = 3;
            } else if (_RB3 == 0) {
                col = 3;
            } else if (_RB4 == 0) {
                col = 3;
            } else if (_RB5 == 0) {
                col = 3;
            } else {
                col = 5;
            };        
        };
    };
    
    switch(row) {
        case 1:
        {
            if (col == 1) {
                return 1;
            } else if (col == 2) {
                return 2;
            } else if (col == 3) {
                return 3;
            }
            break;
        }
        case 2:
        {
            if (col == 1) {
                return 4;
            } else if (col == 2) {
                return 5;
            } else if (col == 3) {
                return 6;
            }
            break;
        }
        case 3:
        {
            if (col == 1) {
                return 7;
            } else if (col == 2) {
                return 8;
            } else if (col == 3) {
                return 9;
            }
            break;
        }
        case 4:
        {
            if (row == 4){
                return 0;
            }
            break;
        }
        default: 
        {
            return 99;
            break;
        }
    };
}

void main() {
    AD1PCFG = 0xFFFF;
    TRISD = 0x00;
    TRISB = 0b00111100;
    TRISE = 0x00;
    int init = 0;
    while(1) {
        LATE = 0x00;
        msDelay(10);
        while (init < 5){
            msDelay(1000);
            disp1();
            init++;
        }
        disp2();
    }
}