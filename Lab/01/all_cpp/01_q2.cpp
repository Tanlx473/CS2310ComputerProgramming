//
//  main.cpp
//  Lab_01_Q2
//
//  Created by Jeremy Tan on 2025/9/2.
//

#include <iostream>
using namespace std;
int main() {
    int i = 5;
    char a = 'A';
    double x = 1.23;
    i = i - x;
    x = x*a;
    cout << "Value of i is " << i << "\n";
    cout << "Value of x is " << x << "\n";
    return 0;
}

//Output：
//Value of i is 3
//Value of x is 79.95

//Why this happens?
//1. Type conversion (implicit):
//      int + double → result is double, then assigned back to int, so decimal part is truncated.
//2. Char's arithmetic:
//      Characters in C++ are actually small integers (ASCII codes). 'A' is 65, so x*a == 65 * 1.23 == 79.95.
