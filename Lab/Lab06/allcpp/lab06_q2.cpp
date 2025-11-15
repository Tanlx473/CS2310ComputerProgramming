//
//  main.cpp
//  lab06_q2
//
//  Created by Jeremy Tan on 2025/10/18.
//

#include <iostream>
using namespace std;

class Record {
public:
    int mon, day;
    double balance;
    
    void getInput() {
        cin>> mon >> day >> balance;
    }
    void print() {
        cout << mon << " " << day << " " << balance << endl;
    }
};

void SortByBalance(Record a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j].balance > a[j + 1].balance) {
                Record temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void SortByDay(Record a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j].mon != a[j + 1].mon) {
                if(a[j].day > a[j].day){
                    Record temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
            if(a[j].mon >= a[j + 1].mon){
                Record temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

Record a[35];
int main(){
    
    cout << "Enter the number of the records: \n";
    int n;
    cin>>n;
    
    cout <<  "Enter the contents of each records: \n";
    for(int i = 0;i < n; i++){
        a[i].getInput();
    }
    
    cout << "Sort according to the balance: \n";
    SortByBalance(a,n);
    for(int i = 0;i < n; i++){
        a[i].print();
    }
    
    cout << "Sort according to the time: \n";
    SortByDay(a,n);
    for(int i = 0;i < n; i++){
        a[i].print();
    }
    
    return 0;
}
