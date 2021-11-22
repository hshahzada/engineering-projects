/*
 * Name: Haashim Shahzada
 * Student ID: 500953004
 * Section 03
 * Created on September 29, 2021, 8:55 PM
 */

// importing libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "Lab2.h"

void initialize(double& k, int& n0) { // initializing function that takes in k, n0 values
    if (k == 0 && n0 == 0) { // if the k values and n0 values do not have values attached
        cout << "Initializing Bacteria:" << endl; // print Initializing Bacteria:
        cout << "\tGrowth Factor: (k) [0.0-1.0] : "; // print [TAB] Growth Factor: (k) [0.0-1.0] : 
        cin  >> k; // take user input for k
        cout << "\tInitial Population (N0) [1-1000] : "; // print [TAB] Initial Population (N0) [1-1000] :
        cin  >> n0; // take user input for n0
    }
    
    else { // if values for k and n0 already attached
        cout << "Initializing Bacteria:" << endl; // print Initializing Bacteria:
        cout << "\tGrowth Factor: (k) [0.0-1.0] : " << k << endl; // print [TAB] Growth Factor: (k) [0.0-1.0] : k value
        cout << "\tInitial Population (N0) [1-1000] : " << n0 << endl; // print [TAB] Initial Population (N0) [1-1000] : n0 value
    }        
}

void calculate( const double k, const int n0, double array[]) { // calculate function that takes in k, n0 and spits out the calculated values in an array
    for (int i = 0; i < 11; i++) { // for 10 iterations
        array[i] = n0*exp(i*k); // calculate n0*the exponential of i time k
    }
}

void display(const double array[]) { // displays the results
    cout << "\tGrowth Summary:"     << endl; // print [TAB] Growth Summary:"
    cout << endl << "\tHour     Population" << endl; // hour and population headings"
    cout << "\t====     ==========" << endl; // print separator line"
    for (int i = 0; i < 10; i++) { // for 9 iterations
        cout << "\t" << i << "        " << array[i] << endl; // print out array values with i being 0-9 indexes
    }
    cout << "\t" << "10" << "       " << array[10] << endl; // print out array index number 10 separate to fix formatting
}

void twoDdisplay(int num, const double arr[][11]) {
    char equals = '='; // saving equals for separator
    cout << endl << "\tagar Summary:" << endl;  // print agar summary heading
    cout << endl; // extra line for spacing
    cout << "\tHour"; // hour heading
    for (int i = 0; i < num; i++) { // for num iterations as specified in function argument
        cout << setw(18) << "Population(" << i << ")"; // space out by 18 units and print population with the i index
    }
    cout << endl; // extra spacing line
    cout << "\t=====" << string(num*20, equals) << endl; // print out equals ("=") num*20 as num is declared to create separator line
    for (int i = 0; i < 11; i++) { // for 10 iterations
        cout << "\t   " << i; // print out hours
        for (int j = 0; j < num; j++) { // for num iterations within the 10 iterations
            cout << setw(20) << arr[i][j]; // print out the array values wit 20 unit spacing
        }
        cout << endl; // line for spacing
    }
}

int main(int argc, char* argv[]) {
    
    double k = 0; 
    int n0 = 0; 
    double array[11]; 
    
    //Part I
    if (1 == argc) { // if the command line argument is lab2proj.exe
        initialize(k, n0); // call initialize function with k and n0 being treated as pointers
        cout << endl;// spacing
        calculate(k, n0, array); // calculate function
        display(array); // display result
    }
    //Part III 
    else if (2 == argc) { // if the command line argument is lab2proj.exe AND any number
        int arguments = atoi(argv[1]); // turn argument from string to float and save as arguments
        double kvalues[arguments]; // make an array the size of arguments for the incoming k values
        int n0values[arguments]; // make an array the size of arguments for the incoming n0 values
        double twodimensionArray[11][11]; // create a 2D array for the output
        for(int i = 0; i < arguments; i++) { // for argument number of iterations
            initialize(k, n0); // call initialize
            kvalues[i] = k; // make kvalues at index i equal to the value of k
            n0values[i] = n0; // make n0values at index i equal to the value of n0
            k = 0; n0 = 0; // reset k and n0
            calculate(kvalues[i], n0values[i], array); // calculate function with the kvalues at index i and n0values at index i as parameters
            for (int j = 0; j < 11; j++) { // for 10 iterations
                twodimensionArray[j][i] = array[j]; // create a 2D array using each array that is spit out by calculate and save it in [j][i] index placement 
            }  
        }
        twoDdisplay(arguments, twodimensionArray); // call function with arguments and 2D array as the params 
    }
    //Part II
    else if (3 == argc) {   // if the command line argument is lab2proj.exe AND BOTH k and n0 values
        k = atof(argv[1]); // turn k from string to double
        n0 = atoi(argv[2]); // turn n0 from string to double
        initialize(k, n0);
        cout << endl; // initialize function
        calculate(k, n0, array); // calculate function
        display(array);  // display result
    }
    else {
        cout << "Number of command-line arguments "
             << "(including the name of the program) "
             << "should be three or less." << endl;
    }
} //end of main

