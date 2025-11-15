//
// Created by Jeremy Tan on 4/11/2025.
//
#include <iostream>
#include <cstring>
using namespace std;
class Candy {
    public:
    int price;
    int amount;
    char* name;
    Candy() {
        price = 10;
        amount = 20;
        name = new char[strlen("strawberry")+1];
        strcpy(name, "strawberry");
    }

    Candy(int p, int a, char* n) {
        price = p;
        amount = a;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Candy(const Candy& c) {
        price = c.price;
        amount = c.amount;
        name = new char[strlen(c.name) + 1];
        strcpy(name, c.name);
    }
    ~Candy() {
        delete[] name;
    }
};

int main() {
    int cho;
    cout<<"Which constructor to use (1: default, 2: parameterized, 3: copy)?\n";
    cin>>cho;
    cin.ignore();

    switch(cho) {
        case 1: {
            Candy c1;
            cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;
            break;
        }
            case 2: {
            char s[100];
            int p, a;

            cout << "Enter name: \n";
            cin.getline(s, 100);

            cout << "Enter price: \n";
            cin >> p;

            cout << "Enter amount: \n";
            cin >> a;

            Candy c1(p, a, s);
            cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;

            break;
        }
            case 3: {
            char s[100];
            int p, a;

            cout << "Enter name: " << endl;
            cin.getline(s, 100);

            cout << "Enter price: " << endl;
            cin >> p;

            cout << "Enter amount: " << endl;
            cin >> a;

            Candy c1(p, a, s); // 第一个对象
            Candy c2 = c1;
            cout << "c1: name-" << c1.name << "; price-" << c1.price << "; amount-" << c1.amount << endl;
            cout << "c2: name-" << c2.name << "; price-" << c2.price << "; amount-" << c2.amount << endl;

            break;
        }

    }
    return 0;
}