/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lab1.cpp
 * Author: Haashim Shahzada
 * Student #: 500953004
 * Created on September 12, 2021, 2:15 PM
 */


#include "lab1.h"

using namespace std;

string enterDNAString(){ // creates a function called compliment that takes no parameters
    string DNAstr; // creates a string variable called DNAstr
    cout << "Please input a DNA String \n"; // outputs "Please input a DNA String" to the user
    cin >> DNAstr; // gets an input from the user and saves it in DNAstr
    return DNAstr; // returns the DNAstr variable
}

bool checkValidity(string s){ // creates a function called checkValidity that takes one string parameter s
bool validation; // creates a bool variable name validation
string uppers = "ATCG"; // creates a string for the uppercase bases
string lowers = "atcg"; // creates a string for the lowercase bases
for(int i = 0; i < s.size(); i++) { // for however long the string s is
    // if the string at index i does not equal any of these conditions
    if ((s[i] != uppers[0]) && (s[i] != uppers[1]) && (s[i] != uppers[2]) && (s[i] != uppers[3]) && (s[i] != lowers[0]) && (s[i] != lowers[1]) && (s[i] != lowers[2]) && (s[i] != lowers[3])){
        validation = false; // set validation to false
        break; // break the loop
    }
    else{ // otherwise
        validation = true; //set the validation variable to true
    }
}
return validation; // return the validation result
}

void compliment(string s){ // creates a function called compliment that takes one string parameter s
string uppers = "ATCG"; // creates a string for the uppercase bases
string lowers = "atcg"; // creates a string for the lowercase bases
string soriginal = s; // creates a variable called soriginal that saves the s string
if (checkValidity(s) == true){ // if the checkValidity function with a parameter of s returns a value of true
    for(int i = 0; i < s.size(); i++) { // for the length of the string s
        if (s[i] == uppers[0]){ // if the character of s at an index of i is equal to A
            s[i] = uppers[1]; // change the character of s at an index of i to T
        }
        else if (s[i] == uppers[1]){ // if the character of s at an index of i is equal to T
            s[i] = uppers[0]; // change the character of s at an index of i to A
        }
        else if (s[i] == uppers[2]){ // if the character of s at an index of i is equal to C
            s[i] = uppers[3]; // change the character of s at an index of i to G
        }
        else if (s[i] == uppers[3]){ // if the character of s at an index of i is equal to G
            s[i] = uppers[2]; // change the character of s at an index of i to C
        }
        else if (s[i] == lowers[0]){ // if the character of s at an index of i is equal to a
            s[i] = lowers[1]; // change the character of s at an index of i to t
        }
        else if (s[i] == lowers[1]){ // if the character of s at an index of i is equal to t
            s[i] = lowers[0]; // change the character of s at an index of i to a
        }
        else if (s[i] == lowers[2]){ // if the character of s at an index of i is equal to c
            s[i] = lowers[3]; // change the character of s at an index of i to g
        }
        else if (s[i] == lowers[3]){ // if the character of s at an index of i is equal to g
            s[i] = lowers[2]; // change the character of s at an index of i to c
        }
    }
    cout << " : compliment(" << soriginal << ") = " << s; // output the original string and then the complimented string
}
return;
}

int main()
{
   while(true) {    
        cout << "Please choose an option:" << endl;
        cout << "1. Enter DNA string, echo it" << endl;
        cout << "2. Enter DNA string, echo it, validate it" << endl;
        cout << "3. Enter DNA string, echo it, validate it, compliment it if valid"
             << endl;
        cout << "4. Exit" << endl;
        
        int option;
        cout << ">> ";
        
        cin >> option;         
        
        //Following "if" statement is to avoid problem with cin
        //if a non-numeric character is read by cin when
        //it is actually supposed to read an integer.
        if ( !cin )  {
            cin.clear();
            cin.ignore( INT_MAX, '\n' );
            cout << "Non-numeric option! Try again." << endl;
            continue;
        }
        
        if (1 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            cout << endl;
        } 
        else if (2 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            bool b = checkValidity(str1);
            if(b == true)                    
                cout << " : VALID DNA";            
            else                    
                cout << " : INVALID DNA";             
            cout << endl;
        }
        else if (3 == option) {
            string str1 = enterDNAString();
            cout << str1 << " (" << str1.size() << " chars)";
            bool b = checkValidity(str1);
            if(b == true)
                cout << " : VALID DNA";
            else
                cout << " : INVALID DNA";
            compliment(str1);
            cout << endl;
        }   
        else if (4 == option) {
            return 0;
        }   
        else {            
            cout << "Integer option, but incorrect! Try again." << endl;
        }     
     }    
     return 0;
}