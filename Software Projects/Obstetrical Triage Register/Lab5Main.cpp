/*
 * Name: Haashim Shahzada
 * Student ID: 500953004
 * Section 03
 * Created on November 7, 2021, 1:36 PM
 */

#include "OTPRegister.h"

int main(void){
    int option;
    string name;
    int number;
    int i = 0;
    OTPRegister myRegister;
    while(option != 4){
        cout << "==================" << endl;
        cout << "There are currently " << myRegister.getSize() << " patient(s) in the list" << endl;
        cout << "Please choose an option:" << endl
             << "1. Register Patient" << endl
             << "2. Examine Patient" << endl
             << "3. Display Patients" << endl
             << "4. Quit" << endl;
        cin >> option;
        cout << "==================" << endl;
        switch(option){
        case 1:
            cout << "[Register patients]" << endl;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter Health Card Number: ";
            cin >> number;
            myRegister.getPatientInfo(name, number);
            cout << ".. [Registering]" << endl;
            break;
        case 2:
            myRegister.patientStatus();
            break;
        case 3:
            myRegister.displayPatients();
            break;
        case 4:
            break;
        default:
            cout << "Invalid Option" << endl;
        }
    }
    return 0;
}