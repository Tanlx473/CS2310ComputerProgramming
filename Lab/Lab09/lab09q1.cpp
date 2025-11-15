//
// Created by Jeremy Tan on 11/11/2025.
//
//Lab09 Q1

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream fin;
    ofstream fout;

    fin.open("lab09.txt");
    if (!fin.is_open()) {
        cout << "Error, please check the file" << endl;
        exit(1);
    }

   fout.open("lab09_output.txt");

    int n;
    fin >> n;

    string _;
    getline(fin, _);


    for (int i = 1; i <= n; i++) {
        string line;
        getline(fin, line);

        int comma_pos = line.find(',');
        int space_pos = line.find(' ', comma_pos + 2);

        string name = line.substr(0, comma_pos);
        string id = line.substr(comma_pos + 2, space_pos - (comma_pos + 2));
        string tel = line.substr(space_pos + 1);

        fout << "Student " << i << ":\n";
        fout << "Name: " << name << endl;
        fout << "Student ID: " << id << endl;
        fout << "Tel: " << tel << "\n\n";
    }

    fin.close();
    fout.close();
    return 0;
}
