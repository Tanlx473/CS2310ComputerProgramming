//
//  main.cpp
//  Lab_01_OQ1
//
//  Created by Jeremy Tan on 2025/9/2.
//

#include <iostream>
using namespace std;
int main() {
    char vChar1,vChar2;
    vChar1 = 'B';
    vChar2 = '9';
    cout<<"The values of vChar1 and vChar2: "<<vChar1<<" "<<vChar2<<endl;

    vChar1 = vChar1 - 1;
    
    cout<<"The value of vChar1 now: "<<vChar1<<endl;
    return 0;
}

// The output of step 3 :
//      The values of vChar1 and vChar2: B 9
// The output of step 5:
//      The value of vChar1 now: A
// Subtraction -- Char's arithmetic:
// Type conversion (implicit,or also can be seen as a type promotion): Characters in C++ are actually small integers (ASCII codes). char - int → result is int, 'B' is 66,vChar1 - 1 == 66 - 1 == 65
// ASCII code 65 corresponds to the character 'A'.vChar is a char variable, so it converted int(65) to char A.Type conversion (implicit)

//What can we learn?
//character arithmetic on works on its ASCII code.(Type conversion)
