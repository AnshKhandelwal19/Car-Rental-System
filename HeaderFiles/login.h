#include <iostream>
#include <iomanip>
#include <vector>
#include "file.h"

using namespace std;

vector<Employee> employee_database;

int findUser(string findUsn) {
    for(int i = 0; i < employee_database.size(); i++) {
        if(employee_database[i].usn == findUsn) {
            return i;
        }
    }
    return -1;
}

void createEmployeeDatabase(vector<string> loginInfo) {
    for(int i = 0; i < loginInfo.size(); i++) {
        Employee e = {loginInfo[i].substr(0, loginInfo[i].find(",")), loginInfo[i].substr(loginInfo[i].find(",")+1)};
        employee_database.push_back(e);
    }
}

bool login() {
    bool successfulLogin = false;
    //Read admin text file to get username and passwords to allow to login to system
    createEmployeeDatabase(readFile("TextFiles/admin.txt"));
    if(employee_database.size() == 0) {
        exit(1);
    }

    //Begin asking user to login
    string usn, psw;
    int pos, count = 0, tries = 0;

    cout << "---------LOGIN---------" << endl;
    while(true) {
        cout << "Username" << endl;
        cin >> usn;
        pos = findUser(usn);
        if(pos != -1) {
            while(count < 3) {
                cout << "Password" << endl;
                cin >> psw;
                if(employee_database[pos].psw == psw) {
                    return true;
                }
                else {
                    cout << "Incorrect password" << endl;
                    count++;
                }
            }
            cout << "Three incorrect attempts, please try again later" << endl;
            return false;
        }
        else {
            cout << "User not found, try again." << endl;
        }
    }
}


