//
//  q1
//
//  Created by Jeremy Tan on 2025/10/14.
//  Development Environment:
//      Operating System: macOS Tahoe 26.0 (25A354)
//      Compiler: g++ (Apple clang version 17.0.0)
//      IDE: Xcode

#include <iostream>
using namespace std;

int main() {
    int n;
    while (true) {
        cout << "Enter an integer not less than 3:\n";
        cin >> n;
        if (n >= 3) {
            cout << "The input is valid!\n";
            break;
        } else {
            cout << "Invalid value. Input again!\n";
        }
    }
    
    for(int i = 0; i < n-1; i++){
        for(int j = 1; j <= n; j++){
            if (j == n) cout<<"*";
            else if (j == n-i)   cout<<"*";
            else    cout<<" ";
                
        }
        cout<<endl;
    }
    
    for (int i = 0;i< 2*n-1; i++)   cout<<"*";
    cout<<endl;

    for(int i = n-2; i >= 0; i--){
        for(int j = 1; j <= 2*n-1; j++){
            if (j == n) cout<<"*";
            else if (j == n + i)   cout<<"*";
            else    cout<<" ";
                
        }
        cout<<endl;
    }
    return 0;
}
