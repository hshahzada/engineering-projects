/* 
 * File:   Lab3.cpp
 * Student ID: 500953004
 * Author: Haashim Shahzada
 *
 * Created on October 5, 2021, 1:01 PM
 */

#include <iostream>
#include <cstdlib>
#include "Lab3.h"

//accessSalaryArrayByPointerArithmetic function that takes in no parameters
void accessSalaryArrayByPointerArithmetic() { 
    int salary[3]; //defines an array named salary of size 3 that fills with integers
    
    cout << endl; // print empty line
    
    for (int i = 0; i < 3; ++i) { // for 3 iterations
        cout << "Enter Salary: "; // print enter salary
        cin  >> *(salary + i); // take in a user input for salary and using pointers store the input in the corresponding index location of the salary array
    }
    
    cout << endl; // print an empty line
    cout << "The entered salaries are:" << endl; // print "the entered salaries are:" followed by an empty line
    
    for (int i = 0; i < 3; ++i) { // for 3 iterations
        cout << *(salary + i) << " "; // print the value of the salary previously saved into salary[] by accessing the location of the index through a pointer
    }
    
    cout << endl; // print an empty line
    cout << "Updated salaries are:" << endl; // print "updated salaries are:" followed by an empty line
    
    for (int i = 0; i < 3; i++) { // for 3 iterations
        *(salary + i) = *(salary + i) + *(salary + i) / (i + 1); // update each element using pointers based on the original equation shown in the lab document
        cout << *(salary + i) << " "; // print the updated value found through equation
    }
    cout << endl; // print an empty line

}

//accessSalaryArrayByPointerArithmetic function that takes in a variable pointing to an array of integers and the size of this array as parameters
int* sortIntegersByPointerArithmetic(int* arr, int size) { 
//this loop essentially checks if the previous value is larger than the value in front of it and if so it switches its placement it does this for every placement that satisfies the if condition.
    for (int i = 0; i < size; i++) {	// for size number of iterations	
        for (int j = i+1; j < size; j++) { // within the initial loop, for size number of iterations
            if ( *(arr + i) > *(arr + j) ){ // if the element at position i is greater than the element at position j
                int store = *(arr + i); // "store" the value of the element at position i temporarily to do the switch later on
                *(arr + i) = *(arr + j); // set the value of the element at position i equal to the value of the element at position j
                *(arr + j) = store; // set the value of element at position j equal to the value of store
            }
        }
    }
    return arr; //return the sorted array.
}

int main (int argc, char* argv[]) {
    
    string p1("part1");
    string p2("part2");
    
    if ( 0 == p1.compare(argv[1]) ) {
        accessSalaryArrayByPointerArithmetic(); // call the accessSalaryArrayByPointerArithmetic function
    }
    
    if ( 0 == p2.compare(argv[1]) ) {
        
        int size = 10; //defines a variable size and sets it equal to 10
        int originalArray[size]; //creates an array that takes integers named integerArray of size "size"
        int* sortedArray; //creates a pointer variable named sortedArray that will point to the sorted array
        
        for (int i = 0; i < size; i++) { // for "size" number of iterations
         *(originalArray + i) = atoi(argv[i + 2]); // save the integers passed by through the command-line argument into the integerArray using pointers
        }
        
        cout << endl << "Numbers were entered in command-line in the following order:" << endl; // print this statement
        
        for (int i = 0; i < size; i++){ // for "size" number of iterations
            cout << *(originalArray + i) << " "; // prints each value of the integerArray with a space after each value
        }
        
        sortedArray = sortIntegersByPointerArithmetic(originalArray, size); // save the return array of the sortIntegersByPointerArithmetic as sortedArray with sortIntegersByPointerArithmetic taking in 2 parameters (the command line array and the size of the array)
        cout << endl << "The numbers in ascending order are:" << endl; // prints out this statement
        
        for (int i = 0; i < size; i++){ // for "size" number of iterations
            cout << *(sortedArray + i) << " "; // prints out the value of each element of the sorted array using pointers
        }
        cout << endl; // prints an empty line
    }

}//end of main

