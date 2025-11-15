//
//  main.cpp
//  Lab03_Q1
//
//  Created by Jeremy Tan on 2025/9/16.
//

#include <iostream>
using namespace std;

int main() {
    const int N = 6;
    int a[N];

    cout << "Enter the element in the array:\n";
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // insertion sort 
    for (int i = 1; i < N; ++i) {
        int key = a[i];
        int j = i - 1;
        // Scan the ordered part of array one by one from the largest
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    cout << "The sorted array is:\n";
    for (int i = 0; i < N; ++i) {
        if (i) cout << ", ";
        cout << a[i];
    }
    cout <<endl;
    return 0;
}
