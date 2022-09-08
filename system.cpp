#include <iostream>
#include <fstream>
#include "empFunctions.h"

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

    registerEmp();
    cout << employee_database.back().usn << endl;

    return 0;
}

void setup() {
    
}