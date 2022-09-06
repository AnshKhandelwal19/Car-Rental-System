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