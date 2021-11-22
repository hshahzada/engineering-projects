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
#include <deque>
#include <iomanip>
#include <cstdlib>
#include "Patient.h"

using namespace std;

#ifndef OTPREGISTER_H
#define OTPREGISTER_H

class OTPRegister {
private:
    deque<Patient *>  PatQueue;
public:
    int getSize();
    void getPatientInfo(string line, int healthCard);
    void patientStatus();
    void displayPatients();
    OTPRegister(); 
//    ~OTPRegister();
};

#endif