//
// Created by Jeremy Tan on 2025/10/22.
//

#include <iostream>
using namespace std;

void findWord(char *arr, int *i, int *count)
{
    *count += 1;
    int ch_num = 0;
    while (arr[*i] != ' ')
    {
        ch_num += 1;
        *i += 1;
    }
    cout << "Word "<< *count << " has " << arr[*i] <<" characters."<< endl;

}

int main()
{
    char s[1000];
    cout << "Enter the content of the string: \n";
    cin.getline(s, 1000);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {continue;}
        else if (s[i] == '\0') {break;}
        else {
            int word_num = 0;
            findWord(&s[i],&i,&word_num) ;
        }
    }
    cout << endl;
    return 0;

}