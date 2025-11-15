//
//  main.cpp
//  lab4q3
//
//  Created by Jeremy Tan on 2025/9/30.
//

#include <iostream>
#include <cstring>
using namespace std;
void sort_a_string(char* a){
    int len = strlen(a);
    // insertion sort
    for (int i = 1; i < len; ++i) {
        int key = a[i];
        int j = i - 1;
        // Scan the ordered part of array one by one from the largest
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

}
int main() {
    char s1[50];
    char s2[50];
    cout<<"Input String 1: \n";
    cin>>s1;
    cout<<"Input String 2: \n";
    cin>>s2;

    strcat(s1,s2);
    sort_a_string(s1);
    cout<<s1<<endl;
    return 0;
}
