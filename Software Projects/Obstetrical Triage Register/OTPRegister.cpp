/*
 * Name: Haashim Shahzada
 * Student ID: 500953004
 * Section 03
 * Created on November 7, 2021, 1:36 PM
 */

#include "OTPRegister.h"

OTPRegister::OTPRegister(){}

//OTPRegister::~OTPRegister(){
//    cout << "calling dtor";
//    int qSize = PatQueue.size();
//    for (int i = 0; i < qSize; ++i){
//        delete PatQueue[i];
//        PatQueue[i] = 0;
//    }
//}

void OTPRegister::getPatientInfo(string name, int healthCard){
    Patient * p = new Patient(name, healthCard, UNKNOWN, 0);
    PatQueue.push_back(p);
}

void OTPRegister::patientStatus(){
    
    int dilation;
    
    if (PatQueue.empty()) return;
    
    Patient * p = PatQueue[0];
    
    PatQueue.pop_front();
    cout << "[Examine Patient]" << endl;
    cout << "Enter name: " << p->getName() << endl;
    cout << "Enter Health Card Number: " << p->getHealthCard() << endl;;
    cout << "Enter Cervix Dilation: ";
    cin >> dilation;
    
    p -> setDilation(dilation);
    
    if ((p->getDilation() >= 4)){
        p->setState(2);
        PatQueue.pop_front();
    }
    if ((p->getDilation() < 4)){
        p->setState(1);
        PatQueue.push_back(p);
    }
}

int OTPRegister::getSize(){
    return PatQueue.size();
}

void OTPRegister::displayPatients(){
    cout << "[Display Patients]" << endl;
    int qSize = PatQueue.size();
    for (int i = 0; i < qSize; i++){
        cout << PatQueue[i]->getName(); 
        cout << " " << PatQueue[i]->getHealthCard(); 
        cout << " " << PatQueue[i]->getDilation();
        if (PatQueue[i]->getState() == 0){
            cout << " " << "UNKNOWN" << endl;
        }
        else if (PatQueue[i]->getState() == 1){
            cout << " " << "LABOUR" << endl;
        }
        else if (PatQueue[i]->getState() == 2){
            cout << " " << "ADMIT" << endl;
        }
    }
}
