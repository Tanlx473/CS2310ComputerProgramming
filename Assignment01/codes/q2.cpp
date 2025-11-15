//
//  q2
//
//  Created by Jeremy Tan on 2025/10/14.
//  Development Environment:
//      Operating System: macOS Tahoe 26.0 (25A354)
//      Compiler: g++ (Apple clang version 17.0.0)
//      IDE: Xcode

#include <iostream>
using namespace std;

int main(){
    char pl[100] = {'\0'};
    char cy[100] = {'\0'};
    
    const char key[] = "cityu";
    const int keyLen = sizeof(key) - 1;

        cout << "Input ciphertext:\n";
        cin >> cy;

    for (int i = 0; cy[i] != '\0'; ++i) {
        char c_cy = cy[i];
        int k = i % keyLen;
        int bias = (key[k] - 'a') + 1;
        int v = (c_cy - 'a') - bias;
        int c_pl_value = ((v % 26) + 26) % 26;
        char c_pl = (char)(c_pl_value + 'a');
        
        pl[i] = c_pl;
    }
    
    int pl_end = 0;
    while (pl[pl_end] != '\0') pl_end++;
    
    pl[pl_end] = '\0';
    cout<< "Output plaintext:\n";
    cout << pl << '\n';
    return 0;
}
