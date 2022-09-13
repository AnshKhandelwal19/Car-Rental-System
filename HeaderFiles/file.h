#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Employee{
    string usn;
    string psw;
};

vector<string> readFile(string filename) {
    vector<string> adminLogins;
    string temp;
    fstream fout;
    fout.open(filename);
    if(fout) {  
        while(fout >> temp) {
            adminLogins.push_back(temp);
        }
    }
    else {
        cout << "Error no file found" << endl;
    }
    return adminLogins;
}

void writeToEmployeeDatabase(Employee e) {
    fstream fout;
    fout.open("admin.txt");

    vector<string> file = readFile("TextFiles/admin.txt");
    file.push_back(e.usn + "," + e.psw);

    if(fout) {  
        for(int i = 0; i < file.size(); i++) {
            fout << file[i] << endl;
        }
    }
}