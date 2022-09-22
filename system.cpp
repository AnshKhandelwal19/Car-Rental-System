#include <iostream>
#include <fstream>
#include "HeaderFiles/empFunctions.h"

using namespace std;
struct Day{
    int month;
    int day;
    int year;
};

void setup();

int main() {

    if(!login()) {
        exit(1);
    }

    char input;
    char test;

    while(input != 'e') {

        cout << "What would you like to do?\n\tE -> Employee Commands\n\tC -> Customer Commands\n\tI -> Inventory Commands" << endl;
        cin >> input;
        char test = tolower(input);

        switch (test) {
        case 'e':
            break;
        
        default:
            break;
        }
    }

    return 0;
}