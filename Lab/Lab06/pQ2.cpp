//
// Created by Jeremy Tan on 2025/10/25.
//
#include <iostream>
using namespace std;

class Lock {
private:
    int leftSet, rightSet;      // 目标解锁值
    int leftCount, rightCount;  // 当前计数
    char lastStep;              // 上一次操作方向

public:
    Lock(int leftS, int rightS) {
        leftSet = leftS;
        rightSet = rightS;
        leftCount = 0;
        rightCount = 0;
        lastStep = ' ';
    }

    void turnLeft(int step) {
        if (lastStep == 'r') rightCount = 0;
        leftCount += step;
        lastStep = 'l';
    }

    void turnRight(int step) {
        if (lastStep == 'l') leftCount = 0;
        rightCount += step;
        lastStep = 'r';
    }

    bool unlock() {
        if (leftCount == leftSet && rightCount == rightSet) {
            cout << "Successful!" << endl;
            return true;
        } else {
            cout << "Failed!" << endl;
            lastStep = 'u';
            return false;
        }
        lastStep = 'u';
        return false;
    }

    void reset() {
        leftCount = rightCount = 0;
        lastStep = ' ';
        cout << "Counters reset." << endl;
    }

    void end() {
        cout << "Program terminate!" << endl;
        lastStep = 'e';
    }
};

int main() {
    int leftss, rightss;
    cout << "Enter the value for the left counter:\n";
    cin >> leftss;
    cout << "Enter the value for the right counter:\n";
    cin >> rightss;

    Lock lock1(leftss, rightss);

    while (true) {
        cout << "Enter the operation:\n";
        char operation;
        cin >> operation;

        switch (operation) {
            case 'r': {
                int st;
                cin >> st;
                lock1.turnRight(st);
                break;
            }
            case 'l': {
                int st;
                cin >> st;
                lock1.turnLeft(st);
                break;
            }
            case 'u':
                if (lock1.unlock()) return 0;  // 解锁成功则退出
                break;
            case 's':
                lock1.reset();
                break;
            case 'e':
                lock1.end();
                return 0;
            default:
                cout << "Invalid operation!" << endl;
        }
    }
}
