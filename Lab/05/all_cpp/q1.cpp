//
//  main.cpp
//  q1
//
//  Created by Jeremy Tan on 14/10/2025.
//

#include <iostream>
using namespace std;

void print20to99(int num) {
    string ten_dig[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string one_dig[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    int ten = num / 10;
    int one = num % 10;

    cout << ten_dig[ten];
    if (one != 0) {
        cout << " " << one_dig[one];
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter the integer number: ";
    cin >> num;
    print20to99(num);
    return 0;
}

