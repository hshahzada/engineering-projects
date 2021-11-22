/*
 * Name: Haashim Shahzada
 * Student ID: 500953004
 * Section 03
 * Created on October 14, 2021, 6:41 PM
 */

#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

//enum types
enum bloodTypes {A, AB, O, B};
enum organs {Heart, Kidney, Lung, Liver};

struct patient
{
    char firstName[50];
    char lastName[50];
    bloodTypes bloodType;
    organs organ;
    int age;
    int yearAdded;
    int patientNumber;
};

//function declarations
void patientRecordUpdate(int option, int i, int &numPatients, int &quit, char argument[]);

#endif /* LAB4_H */