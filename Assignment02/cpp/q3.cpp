//
// Created by Jeremy Tan on 16/11/2025.
//
// Question 3
#include <iostream>
using namespace std;
class Combination {
private:
    int dNum;
    int cNum;
    int **pPtr;
public:
    Combination(int i = 1) {
        /************** to be finished **************/
    }
    ~Combination() {
        /************** to be finished **************/
        /***********Remember to release memory*******/
        cout << "Memory is released" << endl;
    }
    void findSum1();
    void findSum2();
    void findSum3();
    /************** to be finished **************/
    void sortBySum();
    void sortByOcc();
};
void Combination::findSum1() {

}
void Combination::findSum2() {
}
void Combination::findSum3() {
}
void Combination::sortBySum() {
}
void Combination::sortByOcc() {
}
void display(Combination &com) {
    int n;
    do {
        cout << "~~~~~~~~~~~~~~~~~" << endl;
        cout << "0 exit" << endl;
        cout << "1 sort by sum" << endl;
        cout << "2 sort by occurrence" << endl;
        cout << "~~~~~~~~~~~~~~~~~" << endl;
        cin >> n;
        switch(n) {
            case 0: cout << "Bye!" << endl; break;
            case 1: com.sortBySum(); break;
            case 2: com.sortByOcc(); break;
        }
        cout << endl;
    } while(n != 0);
}
int main() {
    int drawNum;
    cout << "Enter the number of draw:" << endl;
    cin >> drawNum;
    Combination com(/****/);

    display(com);
    return 0;
}
}