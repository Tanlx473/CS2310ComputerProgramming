//
// Created by Jeremy Tan on 2025/10/25.
//

#include<iostream>
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

int main() {
    int Max_N;
    cout<<"Enter the number of the records: \n";
    cin >> Max_N;
    Record arr[Max_N];
    cout << "Enter the contents of each records: \n";
    for (int i = 0; i < Max_N; i++) {
        arr[i].getInput();
    }

    // Bubble Sort by balance
    for (int i = 0; i < Max_N; i++) {
        for (int j = i+1; j < Max_N; j++) {
            if (arr[i].balance == arr[j].balance) {
                if (arr[i].mon == arr[j].mon) {
                    if (arr[i].day > arr[j].day) {
                        Record temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
                else if (arr[i].mon > arr[j].mon) {
                    Record temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            else if (arr[i].balance> arr[j].balance) {
                Record temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    double target;
    cout<<"Enter the balance to find: \n";
    cin >> target;

    // Binary Search
    int left = 0, right = Max_N, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid].balance == target) {
            found = 1;
            int l_bound = mid;
            while (l_bound > 0 && arr[l_bound-1].balance == target) l_bound--;

            int count = 0;
            int r_bound = l_bound;
            while (r_bound < Max_N && arr[r_bound+1].balance == target) {
                count++;
                r_bound++;
            }

            cout << count << " records found!" << endl;
            for (int i = l_bound; i <= r_bound; i++) {
                arr[i].print();
            }
            return 0;
        }
        if (arr[mid].balance < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (!found)
        cout<<"No record found!"<<endl;

}