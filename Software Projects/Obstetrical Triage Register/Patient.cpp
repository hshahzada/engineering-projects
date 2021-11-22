/*
 * Name: Haashim Shahzada
 * Student ID: 500953004
 * Section 03
 * Created on November 7, 2021, 1:36 PM
 */

#include "Patient.h"

Patient::Patient(string name, int healthCard, condition state, int dilation){
    this->name = name;
    this->healthCard = healthCard;
    this->state = state;
    this->dilation = dilation;
}

void Patient::setState(int status){
    if (status == 0) {
        state = UNKNOWN;
    }
    else if (status == 1){
        state = LABOUR;
    }
    else if (status == 2){
        state = ADMIT;
    }
    
}

void Patient::setDilation(int num){
    dilation = num;
}

const string& Patient::getName(){
    return name;
}

const int Patient::getHealthCard(){
    return healthCard;
}

const int Patient::getDilation(){
    return dilation;
}

const condition Patient::getState(){
    return state;
}
