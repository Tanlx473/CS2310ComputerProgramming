//
// Created by Jeremy Tan on 2025/11/14.
//
#include <iostream>
#include <string>
using namespace std;

class Room {
    private:
    string name;
    string floor;
    int price;
    int status;

    public:
    void set(string n, string f, int p, int s) {
        name = n;
        floor = f;
        price = p;
        status = s;
    }
    void book(string name) {
        if (this->name == name) {
            if (status == 1) {
                status = 0;
                cout << "Succeed!" << endl;
            }
            else {
                cout << "Sorry, the room is not available. Try again." << endl;
            }
        }
    }

    void checkout(string name) {
        if (this->name == name) {
            if (status == 0) {
                status = 1;
                cout << "Thanks for using our services!" << endl;
            }
            else {
                cout << "This room is not booked yet!" << endl;
            }
        }
    }
    void print() {
        cout << name << " " << floor << " " << price << " " << status << endl;
    }

    bool operator>(const Room &r) {
        if (price > r.price) return true;
        if (price < r.price) return false;

        // If prices ==, use compare(name)
        return name.compare(r.name) > 0;
    }

};

class Hotel {
    private:
    int num;
    Room* rPtr;

    void sortRooms() {
        for (int i = 0; i < num - 1; i++) {
            for (int j = 0; j < num - 1 - i; j++) {
                if (rPtr[j] > rPtr[j + 1]) {
                    Room temp = rPtr[j];
                    rPtr[j] = rPtr[j + 1];
                    rPtr[j + 1] = temp;
                }
            }
        }
    }


    public:
    Hotel(int n) {
        num = n;
        rPtr = new Room[num];
    }
    ~Hotel() {
        delete[] rPtr;
    }
    void setRoom(int idx, string n, string f, int p, int s) {
        rPtr[idx].set(n, f, p, s);
    }
    void bookRoom(string rname) {
        for (int i = 0; i < num; i++) {
            rPtr[i].book(rname);
        }
    }
    void checkoutRoom(string rname) {
        for (int i = 0; i < num; i++) {
            rPtr[i].checkout(rname);
        }
    }
    void listRooms() {
        sortRooms();
        cout << "All rooms in the hotel:" << endl;
        for (int i = 0; i < num; i++) {
            rPtr[i].print();
        }
    }

};

// TODOs
int main() {
    int n;
    cout << "Input the number of rooms:" << endl;
    cin >> n;
    Hotel hotel(n);
    cout << "Input the information of each room (room name, floor, price, status):" << endl;
    for (int i = 0; i < n; i++) {
        Room r;
        string n;
        string f;
        int p;
        int s;
        cin >> n >> f >> p >> s;

        // r.set(n, f, p, s);
        hotel.setRoom(i, n, f, p, s);
    }

    cout << endl;
    hotel.listRooms();
    cout << endl;

    string cmd, inf;
    do {
        cout << "Input the instruction:" << endl;
        cin >> cmd;
        if (cmd == "Book") {
            cin >> inf;
            // TODO: book using inf
            hotel.bookRoom(inf);

        } else if (cmd == "Return") {
            cin >> inf;
            // TODO: checkout using inf
            hotel.checkoutRoom(inf);
        } else if (cmd == "List") {
            // TODO:
            hotel.listRooms();
        } else if (cmd == "Leave") {
            // TODO:
            cout << "See you again!" << endl;
            break;
            }


        cout << endl;
    } while(true);
    return 0;
}