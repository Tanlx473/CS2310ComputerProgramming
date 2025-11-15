//
//  main.cpp
//  lab4q1
//
//  Created by Jeremy Tan on 2025/9/29.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char arr[50], name[50], id[20];
    cout << "Enter the student info: ";
    cin.getline(arr, 50);

    int p;
    for (int i = strlen(arr)- 1; i >= 0; i--) {
        if (arr[i] == ' ') {
            p = i;
            break;
        }
    }


    strncpy(name, arr, p);
    name[p] = '\0';          // 记得加结束符
    strcpy(id, arr + p + 1); // 从空格后一位复制到 id

    cout << "Student name is: " << name << endl;
    cout << "Student ID is: " << id << endl;
    return 0;
}

