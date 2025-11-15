#include<iostream>
using namespace std;
class Person {
public:
    Person() { cout << "Person()" << endl; }
    ~Person() { cout << "~Person()" << endl; }

};

class Mother : virtual public Person {
public:
    Mother() { cout << "Mother()" << endl; }
    ~Mother() { cout << "~Mother()" << endl; }
};

class Father : virtual public Person {
public:
    Father() { cout << "Father()" << endl; }
    ~Father() { cout << "~Father()" << endl; }
};

class Child : public Mother, public Father {
public:
    Child() { cout << "Child()" << endl; }
    ~Child() { cout << "~Child()" << endl; }
};

int main() {
    Child c;
    cout<<"Constructed, now destruct it.\n";
    return 0;
}