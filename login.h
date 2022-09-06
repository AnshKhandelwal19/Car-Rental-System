#include <iostream>
#include <vector>
#include "file.h"

using namespace std;

int findUser(vector<Employee> e, string findUsn) {
    for(int i = 0; i < e.size(); i++) {
        if(e[i].usn == findUsn) {
            return i;
        }
    }
    return -1;
}

vector<Employee> createEmployeeLogin(vector<string> loginInfo) {
    vector<Employee> rV;
    for(int i = 0; i < loginInfo.size(); i++) {
        Employee e = {loginInfo[i].substr(0, loginInfo[i].find(",")), loginInfo[i].substr(loginInfo[i].find(",")+1)};
        rV.push_back(e);
    }
    return rV;
}

bool login() {
    bool successfulLogin = false;
    //Read admin text file to get username and passwords to allow to login to system
    vector<Employee> e = createEmployeeLogin(readFile("admin.txt"));
    if(e.size() == 0) {
        exit(1);
    }

    //Begin asking user to login
    string usn, psw;
    int pos, count = 0, tries = 0;

    while(true) {
        cout << "Username: ";
        cin >> usn;
        pos = findUser(e, usn);
        if(pos != -1) {
            while(count < 3) {
                cout << "Password: ";
                cin >> psw;
                if(e[pos].psw == psw) {
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


