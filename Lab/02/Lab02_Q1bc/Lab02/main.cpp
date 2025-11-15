//
//
//  Lab02_Q1.cpp
//
//  Created by Jeremy Tan on 2025/9/9.
//

#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main() {
    double a,b,c;
    //input lengths of 3 sides
    cin>>a;
    cin>>b;
    cin>>c;
    
    //compute the area
    double p = (a+b+c) * 0.5;
    double area = sqrt(p*(p-a)*(p-b)*(p-c));
    
    cout <<fixed << setprecision(2); // 2 digits after the decimal point.
    cout<<"The area is: "<<area<<'\n';

    return 0;
}

