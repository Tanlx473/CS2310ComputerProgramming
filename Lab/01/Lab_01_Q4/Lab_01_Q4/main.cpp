//
//  main.cpp
//  Lab_01_Q4
//
//  Created by Jeremy Tan on 2025/9/2.
//

#include <iostream>
using namespace std;

namespace level1 {
    int a = 0;
    namespace level2 {
        int a = 1;
    }
}

int main()
{
int a = 90;
cout << a << "\n";  //90
cout << level1::a << "\n";  //0
cout << level1::level2::a << "\n";  //1
return 0;
}

//a inside main refers to the local variable int a = 90; so it prints 90.
//level1::a uses the scope resolution operator :: to access a defined in namespace level1 which is 0.
//level1::level2::a accesses a inside the nested namespace level1::level2.
//Try: If write `level2::a` directly in main function, Xcode raise an error said that: Use of undeclared identifier 'level2'.
