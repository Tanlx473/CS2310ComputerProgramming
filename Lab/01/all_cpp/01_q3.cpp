//
//  main.cpp
//  Lab_01_Q3
//
//  Created by Jeremy Tan on 2025/9/2.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int j=3, k=2;
    double y;
    y = j/k;
    cout<<y<<endl;
    //1
    
    y = j/double(k);
    cout<<y<<endl;
    //1.5
    
    y = double(j)/k;
    cout<<y<<endl;
    //1.5
    
    y = double(j/k);
    cout<<y<<endl;
    //1
    
    y = j/2;
    cout<<y<<endl;
    //1
    
    y = j/2.0;
    cout<<y<<endl;
    //1.5
    return 0;
}

//Why:
//Division rules:
//If both operands are integers, the result will also be an integer. The decimal part will be truncated, instead of rounded.
//If one of operands is float or double, C++ may do a type promotion (int → float/double) first, and the result is float/double.



