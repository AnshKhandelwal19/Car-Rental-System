#include <iostream>
#include <fstream>
#include "login.h"

using namespace std;

void registerEmp() {
    string usn, psw, verify_psw;
    bool keepRunning;
    //Register username
    do {
        keepRunning = false;
        cout << "Username: ";
        cin >> usn;
        if(findUser(usn) != -1) {
            cout << "Username already in use." << endl;
            keepRunning = true;
        }
    }while(keepRunning);
    keepRunning = false;
    
    //Add Password
    do {
        keepRunning = false;
        cout << "Password: ";
        cin >> psw;
        cout << "Confirm password: ";
        cin >> verify_psw;
        if(psw != verify_psw) {
            cout << "Passwords do not match." << endl;
            keepRunning = true;
        }
    }while(keepRunning);

    Employee e = {usn, psw};
    employee_database.push_back(e);
}