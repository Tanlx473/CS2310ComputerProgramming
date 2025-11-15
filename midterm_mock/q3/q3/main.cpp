//
//  main.cpp
//  q3
//
//  Created by Jeremy Tan on 2025/10/20.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n = 0;
    double x = 0;

    while(x>1 || x<0.1){
        cout<< "Input x: ";
        cin>>x;

    }
    
    while (n % 2 == 0 || n <= 0){
        cout<< "Input n: ";
        cin>>n;
  
    }
    
    double ans = 0;
    for(int i = 1; i<= n; i++){
        double d = 1;
        for (int j = 1; j <= i; j++){
            d *= x;
        }
        ans += d;
    }
    
    cout<< "Value is: " << fixed << setprecision(2)<< ans << endl;
    return 0;
    
}
