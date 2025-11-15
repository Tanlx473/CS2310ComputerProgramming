//
//  main.cpp
//  pQ1
//
//  Created by Jeremy Tan on 2025/10/24.
//


#include <iostream>
#include <cstring>
using namespace std;

void findWord(char *arr, int *i, int *count)
{
    *count += 1;
    int ch_num = 0;
    while (arr[*i] != ' ' && arr[*i] != '\0')
    {
        ch_num += 1;
        *i += 1;
    }
    cout << "Word "<< *count << " has " << ch_num  <<" characters."<< endl;

}

int main()
{
    char s[1000];
    cout << "Enter the content of the string: \n";
    cin.getline(s, 1000);
    int word_num = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {continue;}
        else if (s[i] == '\0') {break;}
        else {
            
            findWord(s,&i,&word_num) ;
        }
    }
    cout << "The number of words in the string is: "<<word_num<<endl;
    return 0;

}
