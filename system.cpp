#include <iostream>
#include <fstream>
#include "HeaderFiles/empFunctions.h"

using namespace std;

//Function definitions
char getFirstInput();
char employeeCommandsDisplay();
char customerCommandsDisplay();
char inventoryCommandsDisplay();
void run();

int main() {
    
    run();

    return 0;
}

void run() {
    //define variables
    char input;
    while(true) {
        system("clear");
        if(!login())   //login to system
            break;
        while (true) {
            system("clear");
            input = getFirstInput();
            switch (input) {
            case 'e':
                do {
                    input = employeeCommandsDisplay();
                    switch (input) {
                        case 'r':
                            registerEmp();
                            break;
                        case 'd':
                            removeEmp();
                            break;
                        default:
                            break;
                    }
                }while(input != 'e');
                break;
            default:
                break;
            }
            if(input == 'l')
                break;
        }
    }
}

char getFirstInput() {
    bool keepRunning;
    char rV;
    do {
        keepRunning = false;
        cout << "What would you like to do?\n\tE -> Employee Commands\n\tC -> Customer Commands\n\tI -> Inventory Commands\n\tL -> Logout" << endl;
        cin >> rV;
        rV = tolower(rV);
        system("clear");
        if(rV != 'e' && rV != 'c' && rV != 'i' && rV != 'l') {
            cout << "Invalid input - Please try again" << endl;
            keepRunning = true;
        }
    }while(keepRunning);
    return rV;
}

char employeeCommandsDisplay() {
    bool keepRunning;
    char rV;
    do {
        keepRunning = false;
        cout << "What would you like to do?\n\tR -> Register Employee\n\tD -> Remove Employee\n\tE -> Exit" << endl;
        cin >> rV;
        rV = tolower(rV);
        system("clear");
        if(rV != 'r' && rV != 'd' && rV != 'e') {
            cout << "Invalid input - Please try again" << endl;
            keepRunning = true;
        }
    }while(keepRunning);
    return rV;
}