//
//  main.cpp
//  Lab03_Q3
//
//  Created by Jeremy Tan on 2025/9/16.
//

#include <iostream>
using namespace std;
int main() {
    cout<<"Enter the number of rows:\n";
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Please enter positive integer.\n";
        return 0;
    }

    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = i;
    }

    
    for(int i = 1;i<=n;i++){
        for(int j=i-1;j>=0;j--){
            cout<<j<<" ";
        }
        for(int j = 1;j<=n-i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
