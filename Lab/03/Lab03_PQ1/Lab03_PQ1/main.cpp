//
//  main.cpp
//  Lab03_PQ1
//
//  Created by Jeremy Tan on 2025/9/16.
//

#include <iostream>
using namespace std;
int main() {
    int len;

    cout<<"Enter a odd and positive number:\n";
    cin>>len;

    while(len <= 0 || len % 2 != 1){
        cout<<"PLease enter an odd positive number!\n";
        cin>>len;
    }

    for (int i=1 ; i <= (len+1)/2; i++){
        for (int j=1; j<= (len+1)/2 - i; j++){
            cout<<" ";
        }
        for (int m = 1; m <= 2*i-1; m++){
            cout<<"*";
        }
        cout<<endl;
    }

    for (int i=1;i <= (len-1)/2;i++){
        for (int j=1; j<= i;j++)
            cout<<" ";
    
        for(int m=1;m<=len-2*i;m++)
            cout<<"*";
        
        cout<<endl;
    }
    
    return 0;
}
