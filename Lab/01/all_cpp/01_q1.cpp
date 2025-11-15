//
//  main.cpp
//  Lab_01_Q1
//
//  Created by Jeremy Tan on 2025/9/2.
//

#include <iostream>
using namespace std;
int main() {
    int num1;
    int *p;
    num1 = 2147483646;
    p = &num1;
    
    cout << "Value of num1: " << num1 << endl;
   
    cout << "Address stored in p: " << p << endl;
  
    cout << "Value of variable pointed by p: " << *p << endl;
    
    int num2;
    num2 = num1 + 2;
    cout << "Value of num1 and num2: " << num1 <<" "<<num2<< endl;
    
    return 0;
}

/*
 Output:
 Value of num1: 2147483646
 Address stored in p: 0x16fdfee98
 Value of variable pointed by p: 2147483646
 Value of num1 and num2: 2147483646 2147483648
 */

//'int' represents a 32-bit signed integer, with the range being: [-2147483648, 2147483647].
// num1 + 2 == 2147483648, exceeds the maximum number that the int type can represent.
//Computers represent a number following these rules:
//he highest digit of the binary is represented its sign. 0 for positive, 1 for negative
//Positive numbers: stored normally in binary.
//Negative numbers: stored as two’s complement, which means invert all bits and add 1.
//01111111 11111111 11111111 11111110   (2147483646) + 00000000 00000000 00000000 00000010   (2) = 10000000 00000000 00000000 00000000 (-2147483648)

//What can we learned from this exercise?
// A pointer stores the memory address of a variable, and *p can access its value.
// Integers in C++ have a range [-2147483648, 2147483647]. exceeding them may cause overflow.
// To handle larger values safely, we should use a bigger data type such as long long.
