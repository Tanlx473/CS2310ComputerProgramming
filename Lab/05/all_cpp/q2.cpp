//
//  main.cpp
//  q2
//
//  Created by Jeremy Tan on 14/10/2025.
//

#include <iostream>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
    int a, b;
    cout << "Enter the two integers: ";
    cin >> a >> b;

    cout << "The GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    cout << "The LCM of " << a << " and " << b << " is: " << lcm(a, b) << endl;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else
        return gcd(b, a%b);
}
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}
