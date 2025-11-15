//
//  main.cpp
//  q3
//
//  Created by Jeremy Tan on 14/10/2025.
//

#include <iostream>
using namespace std;

int getValue(int num){
    int count_dig = 0;
    int n;
    n = num;
    
    while(num>0){
        num /= 10;
        count_dig++;
    }
    
    int k;
    if(count_dig % 2 == 1)
        k = count_dig / 2 + 1;
    else
        k = count_dig / 2;
    
    int divisor = 1;
    for(int i = 1; i <= k; i++) {
        divisor *= 10;
    }
    return n % divisor;
}

int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;

    int count_dig = 0;
    int n;
    n = num;
    
    while(num>0){
        num /= 10;
        count_dig++;
    }
    
    int k;
    if(count_dig % 2 == 1)
        k = count_dig / 2 + 1;
    else
        k = count_dig / 2;
    cout << "The value of last " << k << " digits of " << n << " is: " << getValue(n) << endl;

    return 0;

}
