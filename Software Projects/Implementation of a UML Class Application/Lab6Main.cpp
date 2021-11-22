#include "ListOfShapes.h"
#include <iostream>

using namespace std;

int main() {
    ListOfShapes shapes;
    string color;
    double length, breadth, radius;
    int choice;
    int numShapes = 0;
    
    do {
        cout << "==========================="                                   << endl;
        cout << "[Shape List]"                                                  << endl;
        cout << "There are currently " << numShapes << " shape(s) in the list"  << endl << endl;
        cout << "Please choose an option: "                                     << endl;
        cout << "1. Add Rectangle"                                              << endl;
        cout << "2. Add Circle"                                                 << endl;
        cout << "3. Remove Shape"                                               << endl;
        cout << "4. Display Shapes"                                             << endl;
        cout << "5. Quit"                                                       << endl;
        cout << ">> ";
        
        cin >> choice;
        
        while(choice < 1 || choice > 5) {
            cout << "Invalid Option" << endl;
            cout << ">> ";
            cin  >> choice;
        }
        
        cout << "=================" << endl;
        
        switch(choice) {
            case 1:
                cout << "[Add Rectangle]" << endl;
                cout << "Enter color: ";
                cin  >> color;
                cout << "Enter length: ";
                cin  >> length;
                cout << "Enter breadth: ";
                cin  >> breadth;
                cout << ".. [Adding Rectangle]" << endl;
                
                shapes.addShape(new Rectangle(color,length,breadth));
                numShapes++;
                break;
            case 2:
                cout << "[Add Circle]" << endl;
                cout << "Enter color: ";
                cin  >> color;
                cout << "Enter radius: ";
                cin  >> radius;
                cout << ".. [Adding Circle]" << endl;
                
                shapes.addShape(new Circle(color, radius));
                numShapes++;
                break;
            case 3:
                cout << ".. [Removing Shape]" << endl << endl;
                shapes.removeShape();
                if(numShapes != 0) {
                    numShapes--;
                };
                break;
            case 4:
                shapes.displayShapes();
                cout << endl;
                break;
            case 5:
                cout << ".. [Quitting]" << endl;
                break;
        }
    }
    
    while (choice != 5);
};

