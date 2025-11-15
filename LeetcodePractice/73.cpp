//
// Created by Jeremy Tan on 2025/10/27.
//
// main.cpp
// LeetCode 73: Set Matrix Zeroes
// CLion test framework
// Created by Jeremy Tan on 2025/10/27

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// ====== Solution skeleton ======
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // 记录哪一行、哪一列需要置零
        vector<int> zero_row(m, 0);
        vector<int> zero_col(n, 0);

        // 第一遍扫描，记录含零的行列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zero_row[i] = 1;
                    zero_col[j] = 1;
                }
            }
        }

        // 第二遍扫描，根据标记置零
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (zero_row[i] || zero_col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// ====== Helper functions ======

// Parse LeetCode-style input: [[1,1,1],[1,0,1],[1,1,1]]
vector<vector<int>> parseMatrix(const string& input) {
    vector<vector<int>> matrix;
    vector<int> row;
    string num;
    for (char c : input) {
        if (isdigit(c) || c == '-' || c == '+') num += c;
        else if (!num.empty()) {
            row.push_back(stoi(num));
            num.clear();
        }
        if (c == ']') {
            if (!row.empty()) {
                matrix.push_back(row);
                row.clear();
            }
        }
    }
    return matrix;
}

// Print matrix as LeetCode format
void printMatrix(const vector<vector<int>>& matrix) {
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j + 1 < matrix[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < matrix.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== LeetCode 73: Set Matrix Zeroes =====\n";
    cout << "Enter test cases (e.g. [[1,1,1],[1,0,1],[1,1,1]]):\n";

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;

        // Parse input
        vector<vector<int>> matrix = parseMatrix(line);

        // Process
        Solution s;
        s.setZeroes(matrix);

        // Output
        cout << "Output:\n";
        printMatrix(matrix);
        cout << "--------------------\n";
        cout << "Next test case (empty line to exit):\n";
    }

    cout << "All tests completed.\n";
    return 0;
}
