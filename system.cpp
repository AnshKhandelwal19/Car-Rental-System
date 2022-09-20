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

    registerEmp();

    removeEmp("AryanP");

    return 0;
}