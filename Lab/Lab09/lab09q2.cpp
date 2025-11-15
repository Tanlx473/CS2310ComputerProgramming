//
// Created by Jeremy Tan on 11/11/2025.
//
// Lab09 Q2

#include <iostream>
#include <string>
using namespace std;
class Candy {
    public:
    int price;
    int amount;
    string name;

    Candy() {
        name = " ";
        price = 0;
        amount = 0;
    }

    Candy(int p, int a, string n) {
        price = p;
        amount = a;
        name = n;
    }



    Candy operator+(const Candy& c2) {
        Candy result;
        result.price = (this->price + c2.price) / 2;
        result.amount = this->amount + c2.amount;
        result.name = this->name + "-" + c2.name;

        return result;
    }

    friend ostream& operator<<(ostream &cout, const Candy& c) {
        cout << "c3: name-" << c.name << "; price-" << c.price << "; amount-" << c.amount << endl;
    }
};

int main() {
    cout << "Enter name:\n";
    string name_1;
    cin >> name_1;
    cout << "Enter price:\n";
    double price_1;
    cin >> price_1;
    cout << "Enter amount:\n";
    int amount_1;
    cin >> amount_1;

    Candy c1(price_1, amount_1, name_1);

    cout << endl;
    cout << "Enter name:\n";
    string name_2;
    cin >> name_2;
    cout << "Enter price:\n";
    double price_2;
    cin >> price_2;
    cout << "Enter amount:\n";
    int amount_2;
    cin >> amount_2;

    Candy c2(price_2, amount_2, name_2);

    Candy c3;
    c3 = c1 + c2;
    cout << c3 << endl;
    return 0;
}