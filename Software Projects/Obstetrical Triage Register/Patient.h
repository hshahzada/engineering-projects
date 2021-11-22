/*
 * Name: Haashim Shahzada
 * Student ID: 500953004
 * Section 03
 * Created on November 7, 2021, 1:36 PM
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <cstdlib>

using namespace std;

#ifndef PATIENT_H
#define PATIENT_H

enum condition {UNKNOWN, LABOUR, ADMIT};  

class Patient {
private:
    string name;
    int healthCard;
    condition state;
    int dilation;
public:
    Patient(string name, int healthCard, condition state, int dilation);
    ~Patient();
    void setDilation(int num);
    void setState(int status);
    const string& getName();
    const int getHealthCard();
    const condition getState();
    const int getDilation();
};

#endif
