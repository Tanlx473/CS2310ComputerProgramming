//
// Created by Jeremy Tan on 2025/11/14.
//
#include <iostream>
using namespace std;

int main() {
    cout << "Please input the size of the matrix:" << endl;
    int si;
    cin >> si;

    cout << "Please input the matrix row by row:" << endl;
    int arr[si][si];
    for (int i = 0; i < si; i++) {
        for (int j = 0; j < si; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "The spiral form of the matrix is:" << endl;
    int b_bound = si-1;
    int r_bound = si-1;
    int t_bound = 0;
    int l_bound = 0;

    while (b_bound >= t_bound && r_bound >= t_bound) {
        // down
        for (int i = t_bound; i <= b_bound; i++) {
            cout << arr[i][l_bound] << " ";
        }
        l_bound++;
        // right
        for (int i = l_bound; i <= r_bound; i++) {
            cout << arr[b_bound][i] << " ";
        }
        b_bound--;
        // up
        for (int i = b_bound; i >= t_bound; i--) {
            cout << arr[i][r_bound] << " ";
        }
        r_bound--;
        for (int i = r_bound; i >= l_bound; i--) {
            cout << arr[t_bound][i] << " ";
        }
        t_bound++;
    }


    return 0;
}