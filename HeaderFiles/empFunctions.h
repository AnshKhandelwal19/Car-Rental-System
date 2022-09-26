#include <iostream>
#include <fstream>
#include "login.h"

using namespace std;

//Function definitions
void registerEmp();
void removeEmp();
void printArray(vector<string>);

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

    //code to add to database
    vector<string> file = getFileContent("TextFiles/admin.txt");
    file.push_back(e.usn + "," + e.psw);
    writeToFile(file, "TextFiles/admin.txt");
    system("clear");
    cout << "User " << usn << " has been added." << endl;
}

void removeEmp() {
    string name;
    char validate;
    cout << "Employee Username to be removed: " << endl;
    cin >> name;

    cout << "Are you sure? (Y/N)" << endl;
    cin >> validate;
    if(tolower(validate) != 'y') {
        system("clear");
        return;
    }

    vector<string> file = getFileContent("TextFiles/admin.txt");
    for(int i = 0; i < employee_database.size(); i++) {
        if(employee_database[i].usn == name) {
            employee_database.erase(employee_database.begin()+i);
            file.erase(file.begin() + i);
        }
    }
    writeToFile(file, "TextFiles/admin.txt");
    system("clear");
}

void printArray(vector<string> a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
}