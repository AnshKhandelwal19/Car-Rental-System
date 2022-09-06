#include <iostream>
#include <fstream>
#include "login.h"

using namespace std;
struct Day{
    int month;
    int day;
    int year;
};
struct Car {
    string name;
    double msrp;
    double rent_cost_per_hour;
};
struct Renter{
    string name;

};

int main() {

    if(!login()) {
        exit(1);
    }

    return 0;
}