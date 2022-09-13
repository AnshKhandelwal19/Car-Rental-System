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

    return 0;
}

void setup() {
    
}