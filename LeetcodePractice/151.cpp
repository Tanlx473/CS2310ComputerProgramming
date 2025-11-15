//
// Created by Jeremy Tan on 2025/10/27.
//
// LeetCode 151. Reverse Words in a String
// Author: Jeremy Tan

#include <iostream>
#include <cstring>

using namespace std;

// Cstring：
void reverseWords(char *input) {
        int len = strlen(input);
        if (len == 0) {
                cout << "" << endl;
                return;
        }

        int left = 0;
        while (left < len && input[left] == ' ') left++;
        int right = len - 1;
        while (right >= 0 && input[right] == ' ') right--;
        if (left > right) {
                cout << "" << endl;
                return;
        }


        char word[200][200];
        memset(word, 0, sizeof(word));

        int cnt = -1;       // 当前单词编号
        int pos = 0;        // 当前单词内部位置
        bool inWord = false;

        for (int i = left; i <= right; i++) {
                if (input[i] != ' ') { // 非空格字符
                        if (!inWord) {     // 遇到新单词
                                cnt++;
                                pos = 0;
                                inWord = true;
                        }
                        word[cnt][pos++] = input[i];
                } else if (inWord) {   // 单词结束
                        word[cnt][pos] = '\0';
                        inWord = false;
                }
        }


        //最后一个单词
        if (inWord)
                word[cnt][pos] = '\0';


        for (int i = cnt; i >= 0; i--) {
                cout << word[i];
                if (i > 0) cout << " ";
        }
        cout << endl;
}


int main() {
        char input[1000];
        cin.getline(input, 1000);
        reverseWords(input);
        return 0;
}
