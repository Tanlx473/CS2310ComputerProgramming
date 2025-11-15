//
//  main.cpp
//  Lab_01_OQ4
//
//  Created by Jeremy Tan on 2025/9/2.
//

#include <iostream>
using namespace std;
int main() {
    
    int a, b, c, d;
    cout << "Please input the absolute value of a negative 4-bit binary number (from -7 to 0):" << endl;
    cin >> d >> c >> b >> a;
    cout << "Binary Number: -"<< d<< c << b << a << endl;
    
    // task: calculate the two’s complement
    // Get inverts for each digits
    int td = 1 - d;
    int tc = 1 - c;
    int tb = 1 - b;
    int ta = 1 - a;
    
    //Get Two's complement
    int na = ta + 1;
    a = na % 2;
    tb += na / 2;

    b = tb % 2;
    tc += tb / 2;
    
    c = tc % 2;
    td += tc / 2;
    
    d = td % 2;
    
    cout << "Two's Complement: " << d << c << b << a <<endl;

    return 0;
}
