//
// Created by Jeremy Tan on 2025/10/25.
//
#include <iostream>
using namespace std;

string d2b(double n);

int main() {
    double n;
    cout<< "Enter the decimal double number: \n";
    cin >> n;
    cout << "The corresponding binary double is: " << d2b(n) << endl;
    return 0;
}

string d2b(double n) {
    int int_n = (int) n;
    double frac_n = n - int_n;
    string b_int = "";
    string b_frac = "";
    if (int_n == 0) {
        b_int = "0";
    }
    else if (frac_n == 0) {
        b_frac = "0";
    }
    else {
        while (int_n) {
            b_int = char(int_n % 2 + '0') + b_int;
            int_n /= 2;
        }
        while (frac_n) {
            frac_n *= 2;
            if (frac_n >= 1) {
                b_frac.append("1");
                frac_n -= 1;
            }
            else {
                b_frac.append("0");
            }
        }
    }
    return b_int + "." + b_frac;
}