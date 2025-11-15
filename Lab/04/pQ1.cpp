//
// Created by Jeremy Tan on 2025/10/25.
//
#include <iostream>
#include <cstring>
using namespace std;
int countSub(char *ch1, char *ch2) {
    int cnt = 0;
    int len1 = strlen(ch1);
    int len2 = strlen(ch2);
    for (int i = 0; i < len1; i++) {
        if (ch1[i] == ch2[0]) {
            int flag = 1;
            for (int j = 0; j < len2; j++) {
                if (ch1[i+j] != ch2[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    char ch1[100] = {'\0'};
    char ch2[100] = {'\0'};
    cout<<"Enter two strings: ";
    cin>>ch1>>ch2;
    cout<<"The occurence of "<<ch2<< " in "<<ch1<<" is: "<<countSub(&ch1[0],&ch2[0])<<endl;
}