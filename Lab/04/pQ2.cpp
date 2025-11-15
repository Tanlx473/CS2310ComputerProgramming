//
// Created by Jeremy Tan on 2025/10/25.
//
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char str[100];
    char str_output[1000];
    char *c = str_output;
    cout << "Enter the input string: \n";
    cin.getline(str, 100);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            *c = '%';
            c++;
            *c = '0';
        }
        else
            *c = str[i];
        c++;
    }
    cout << "The replace string is: "<< str_output <<endl;
}