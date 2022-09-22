#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Function Definitions
vector<string> readFile(string);
vector<string> getFileContent(string);
void writeToFile(vector<string>, string);

struct Employee{
    string usn;
    string psw;
};

vector<string> readFile(string filename) {
    vector<string> fileInfo;
    string temp;
    fstream fout;
    fout.open(filename);
    if(fout) {  
        while(fout >> temp) {
            fileInfo.push_back(temp);
        }
    }
    else {
        cout << "Error no file found" << endl;
    }
    fout.close();
    return fileInfo;
}

vector<string> getFileContent(string fileName) {
    fstream fout;
    fout.open(fileName);

    return readFile(fileName);
}

void writeToFile(vector<string> file, string fileName) {
    ofstream fout;
    fout.open(fileName, ofstream::out | ofstream::trunc); 
    if(fout) {  
        for(int i = 0; i < file.size(); i++) {
            fout << file[i] << endl;
        }
    }
    fout.close();
}