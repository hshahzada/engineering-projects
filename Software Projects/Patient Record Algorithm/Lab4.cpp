/*
 * Name: Haashim Shahzada
 * Student ID: 500953004
 * Section 03
 * Created on October 14, 2021, 6:40 PM
 */

#include "Lab4.h"

using namespace std;

void patientRecordUpdate(int option, int i, int &numPatients, int &quit, char argument[])
{
    int j;
    string bloodType;
    string organ;	
    patient patient[100]; 

    if(option == 1)	
    {
        cout << "=============" << endl
             << "[Add Patient]" << endl
             << "Please enter the Patient Record:" << endl << endl;
        cin  >> patient[i].firstName >> patient[i].lastName >> bloodType >> organ >> patient[i].age >> patient[i].yearAdded;
        cout << ".. [Adding]" << endl;

        if (bloodType == "A") {
            patient[i].bloodType = A;
        }
        if (bloodType == "AB") {
            patient[i].bloodType = AB;
        }
        if (bloodType == "O") {
            patient[i].bloodType = O;
        }
        if (bloodType == "B") {
            patient[i].bloodType = B;
        }
        if ((bloodType != "A") && (bloodType != "AB") && (bloodType != "O") && (bloodType != "B")) {
            cout << "\nInvalid blood type.";
        }

        if(organ == "Heart") {
            patient[i].organ = Heart;
        }
        if(organ == "Kidney") {
            patient[i].organ = Kidney;
        }
        if(organ == "Lung") {
            patient[i].organ = Lung;
        }
        if(organ == "Liver") {
            patient[i].organ = Liver;
        }
        if((organ != "Heart") && (organ != "Kidney") && (organ != "Lung") && (organ != "Liver")) {
            cout << "\nInvalid organ.";
        }

        patient[i].patientNumber = numPatients + 1;

        numPatients++; 

    }

    if(option == 2) 	
    {
        cout << "[Show List of Patients]";
        cout << "\nID\tName\t\tBlood\tOrgan\tAge\tYear Added";
        cout << "\n----------------------------------------------------------------------\n";
           
       for(j = 0; j < numPatients; j++)
       {
           cout << patient[j].patientNumber << "\t" << patient[j].lastName << ", " << patient[j].firstName[0] << "\t";

           //translate info out of enum types
           if (patient[j].bloodType == 0) {
               cout << "A\t";
           }
           if (patient[j].bloodType == 1) {
               cout << "AB\t";
           }
           if(patient[j].bloodType == 2) {
               cout << "O\t";
           }
           if(patient[j].bloodType == 3) {
               cout << "B\t";
           }

           //translate info out of enum type
           if(patient[j].organ == 0) {
               cout << "Heart\t";
           }
           if(patient[j].organ == 1) {
               cout << "Kidney\t";
           }
           if(patient[j].organ == 2) {
               cout << "Lung\t";
           }
           if(patient[j].organ == 3) {
               cout << "Liver\t";
           }

           cout << patient[j].age << "\t" << patient[j].yearAdded << "\n";
        }
    }

    if(option == 3)	//saving patient list to file
    {
        ofstream myfile;	//outputting to file
        myfile.open("transplantPatients.txt");
        myfile << "Patients: " << numPatients << endl;

        myfile << "\nID\tName\t\tBlood\tOrgan\tAge\tWaiting Since";
        myfile << "\n----------------------------------------------------------------------\n";

       for(j = 0; j < numPatients; j++) //outputting to file
       {
           myfile << patient[j].patientNumber << "\t" << patient[j].lastName << ", " << patient[j].firstName[0] << "\t";
           if(patient[j].bloodType == 0) {
               myfile << "A\t";
           }
           if(patient[j].bloodType == 1) {
               myfile << "AB\t";
           }
           if(patient[j].bloodType == 2) {
               myfile << "O\t";
           }
           if(patient[j].bloodType == 3) {
               myfile << "B\t";
           }
           if(patient[j].organ == 0) {
               myfile << "Heart\t";
           }
           if(patient[j].organ == 1) {
               myfile << "Kidney\t";
           }
           if(patient[j].organ == 2) {
               myfile << "Lung\t";
           }
           if(patient[j].organ==3) {
               myfile << "Liver\t";
           }
           myfile << patient[j].age << "\t" << patient[j].yearAdded << "\n\n";
        }
        
        myfile.close();
        cout << "...[Saving]" <<endl;
    }

    if(option == 4) { //quit loop
        quit=1;
    }    
    else if((option!=1) && (option!=2) && (option!=3) && (option!=4))
        cout << "\nInvalid option. Please try again.\n\n";
}

int main(int argc, char *argv[]){
    int i;
    int option;
    int numPatients=0;
    int quit;
    
    if(argc == 1){ //execution in command line without file name
        for(i=0; i<100; i++){
            cout << "=======================\n" << "[Organ Transplant List]\nThere is currently " << numPatients << " patient(s) on the list\n\n";
            cout << "Please choose an option:\n1.    Add patient\n2.    Show Patients\n3.    Save Patient List\n4.    Quit" << endl;
            cin >> option;

            patientRecordUpdate(option,i,numPatients,quit,argv[1]);	//call patientRecordUpdate function

            if(quit==1){
                break;
            }
        }
    }
    
    if(argc==2){ //execution in the command line with file name
        string patientInfo;
        string savedata[100];
        int i = 0;
        for(i=0; i<100; i++){
            cout << "=======================\n" << "[Organ Transplant List]\nThere is currently" << " patient(s) on the list\n\n";
            cout << "Please choose an option:\n1.    Add patient\n2.    Show Patients\n3.    Save Patient List\n4.    Quit" << endl;
            cin >> option;
            
            if (option == 2){
                if(strcmp(argv[1], "transplantPatients.txt") == 0){ //check if argument from command line is "trasnplantPatients.txt"
                    ifstream myfile ("transplantPatients.txt");	//receiving input from file
                    if (myfile.is_open()){
                    while (getline(myfile, patientInfo)){
                        savedata[i] = patientInfo;
                        cout << patientInfo << endl;	//output contents of file
                        i++;
                    }
                    myfile.close();
                    }
                }
            }
            
            if (option == 1 || option == 3 || option == 4){
                patientRecordUpdate(option, i, numPatients, quit, argv[1]);	//call patientRecordUpdate function

                if(quit == 1){
                    break;
                }
            }
        }
    }
   
    else if(argc < 1){
        cout << "Invalid number of arguments.\n";
    }
    return(0);
}


