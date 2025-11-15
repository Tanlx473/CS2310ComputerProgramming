//
// Created by Jeremy Tan on 2025/10/27.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt[bank.size()];
        for(int i=0;i<bank.size();i++) {
            cnt[i] = 0;
            for(int j=0;j<bank[i].size();j++) {
                if(bank[i][j]=='1') {
                    cnt[i]++;
                }
            }
        }

        int ans = 0;
        int m1 = 0, m2 = 0;
        for(int i=0;i<bank.size();i++) {
            if(m1 == 0 && cnt[i] != 0) {
                m1 = cnt[i];
            }
            else if(m1 != 0 && cnt[i] == 0) {
                continue;
            }
            else if(m1 != 0 && cnt[i] != 0) {
                ans += cnt[i] * m1;
                m1 = cnt[i];
            }
        }
        cout << ans << endl;
    }
};

// ------------------- Helper Functions -------------------
vector<string> parseInput(const string &input) {
    // 将输入格式 ["011001","000000","010100"] 解析为 vector<string>
    vector<string> bank;
    string s = input;
    string temp;
    for (char c : s) {
        if (c == '"') continue;
        else if (c == '[' || c == ']') continue;
        else if (c == ',') {
            if (!temp.empty()) {
                bank.push_back(temp);
                temp.clear();
            }
        } else temp.push_back(c);
    }
    if (!temp.empty()) bank.push_back(temp);
    return bank;
}

// ------------------- Main Test -------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter bank (e.g. [\"011001\",\"000000\",\"010100\",\"001000\"]):\n";
    string line;
    getline(cin, line);

    vector<string> bank = parseInput(line);

    Solution sol;
    int result = sol.numberOfBeams(bank);

    cout << "Result: " << result << "\n";

    // 示例测试
    // Input: ["011001","000000","010100","001000"]
    // Expected Output: 8
    return 0;
}
