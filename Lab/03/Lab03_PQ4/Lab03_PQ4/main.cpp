//
//  main.cpp
//  Lab03_PQ4
//
//  Created by Jeremy Tan on 2025/9/19.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int n=6;
    int a[10];
    printf("Enter:\n");
    for (int i=0; i<6;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    
    cout<<"The sorted array is:\n";
    for (int i=0; i<6;i++) {
        cout<<a[i]<<", ";
    }
    cout<<endl;
    cout<<"Enter the number to search:";
    
    int s;
    cin>>s;
    
    
    int l=0, r = 5;
    int c = 0;
    int mid;
    int ans = -1;
    while(l<=r){
        c++;
        mid = (l+r)/2;
        if(s == a[mid]){
            ans = mid;
            break;
        }
        if (s>a[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    
    printf("The position of the element is: %d \n", ans);
    printf("%d iteration used.", c);

    
    
}
