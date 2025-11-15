//
// Created by Jeremy Tan on 2025/10/24.
//
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1000];
    cout << "Enter the string: " << endl;
    cin.getline(str, 1000);

    int len = strlen(str);
    char* suffix[1000]; // 用指针数组存每个后缀的起点

    // Get suffix
    for (int i = 0; i < len; i++) {
        suffix[i] = &str[i];
    }

    // 2. 按字典序排序
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (strcmp(suffix[i], suffix[j]) > 0) {
                char* temp = suffix[i];
                suffix[i] = suffix[j];
                suffix[j] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        cout << suffix[i]<<endl;
    }
}

