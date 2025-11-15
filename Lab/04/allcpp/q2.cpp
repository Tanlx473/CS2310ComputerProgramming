//
//  main.cpp
//  lab4q2
//
//  Created by Jeremy Tan on 2025/9/30.
//

#include <iostream>
#include <cstring>
using namespace std;

bool is_match(char* a,char* b,int h){
    int len=strlen(b);
    for(int i=0;i<len;i++){
        if(a[h+i] != b[i]){
            return false;
        }
    }
    return true;
}
int main() {
    cout<<"The word and chars are:\n";
    char s[100];
    char c[100];
    char f[100];
    int p = -1;
    cin>>s>>c;
    for(int i=0;i<strlen(s);i++){
        if(is_match(s,c,i)){
            p = i;
        }
    }
    
    cout<<"The last position of "<<c<<" is: " <<p<<endl;
    return 0;
}
