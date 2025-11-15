//
//  q3
//
//  Created by Jeremy Tan on 2025/10/14.
//  Development Environment:
//      Operating System: macOS Tahoe 26.0 (25A354)
//      Compiler: g++ (Apple clang version 17.0.0)
//      IDE: Xcode

#include <iostream>
#include <iomanip>
using namespace std;
const int N = 10;
struct Date {
    int day;
    int month;
    int year;
};
struct Employee {
    int id;
    double salary;
    Date date;
};
struct Company {
    int num;
    Employee employees[N];
};
void listOptions() {
    cout<< "~~~~~~~~~Welcome!~~~~~~~~~~\n";
    cout<< "0: Exit\n";
    cout<< "1: Hire\n";
    cout<< "2: Show\n";
    cout<< "3: Transfer\n";
    cout<< "4: Sort\n";
    cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    return;
}
void hire(Company *c) {
    if (c->num >= N) {
        cout << "Department is full\n";
        return;
    }

    cout << "Input Employee ID:\n";
    int id;
    cin >> id;
    
    cout << "Input Salary:\n";
    double sal;
    cin>>sal;
    
    cout<< "Input Date (dd mm yyyy):\n";
    int dd,mm,yyyy;
    cin>>dd>>mm>>yyyy;
    
    c->employees[c->num].id = id;
    c->employees[c->num].salary = sal;
    c->employees[c->num].date.day = dd;
    c->employees[c->num].date.month = mm;
    c->employees[c->num].date.year = yyyy;
    (c->num)++;
    return ;
}
void show(Company *c) {
    if (c->num == 0) {
        cout << "Department is empty\n";
        return;
    }
    
    for(int i = 0; i < c->num; i++){
        cout << setw(3) << setfill('0') << c->employees[i].id<< ' '
        << fixed << setprecision(2) << setfill(' ')<< c->employees[i].salary << ' '
        << c->employees[i].date.day << '-' << c->employees[i].date.month << '-' << c->employees[i].date.year
        << '\n';
    }
    return ;
}
void transfer(Company *c) {
    cout << "Enter the ID to be transferred\n";
    int eid;
    cin >> eid;
    
    int idx = -1;
        for (int i = 0; i < c->num; ++i){
            if (c->employees[i].id == eid) {
                idx = i; break;
            }
        }
    if(idx == -1){
        cout<< "The ID cannot be found\n";
        return ;
    }
    for (int i = idx + 1; i < c->num; ++i) {
        c->employees[i - 1] = c->employees[i];
    }
    (c->num)--;
    return ;
}
void sort_id(Company *c) {
    for (int i = 0; i< c->num; i++){
        for (int j = i+1; j < c->num; j++) {
            if (c->employees[i].id > c->employees[j].id){
                Employee temp;
                temp = c->employees[i];
                c->employees[i] = c->employees[j];
                c->employees[j] = temp;
            }
        }
    }
}
void sort_salary(Company *c) {
    for (int i = 0; i < c->num; ++i) {
        for (int j = i + 1; j < c->num; ++j) {
            bool is_gra = false;
            if (c->employees[i].salary > c->employees[j].salary)    is_gra = true;
            else if (c->employees[i].salary == c->employees[j].salary
                     && c->employees[i].id > c->employees[j].id)
                is_gra = true;
            else    is_gra = false;
            if(is_gra){
                Employee temp = c->employees[i];
                c->employees[i] = c->employees[j];
                c->employees[j] = temp;
            }
            
        }
    }
}
    void sort_date(Company *c) {
        for (int i = 0; i < c->num; ++i) {
            for (int j = i + 1; j < c->num; ++j) {
                bool is_gra = false;
                if (c->employees[i].date.year > c->employees[j].date.year)
                    is_gra = true;
                else if (c->employees[i].date.year == c->employees[j].date.year
                         && c->employees[i].date.month > c->employees[j].date.month)
                    is_gra = true;
                else if (c->employees[i].date.year == c->employees[j].date.year
                         && c->employees[i].date.month == c->employees[j].date.month
                         && c->employees[i].date.day > c->employees[j].date.day)
                    is_gra = true;
                else if(c->employees[i].date.year == c->employees[j].date.year
                        && c->employees[i].date.month == c->employees[j].date.month
                        && c->employees[i].date.day == c->employees[j].date.day
                        && c->employees[i].id > c->employees[j].id)
                    is_gra = true;
                else is_gra = false;
                
                if(is_gra){
                    Employee temp = c->employees[i];
                    c->employees[i] = c->employees[j];
                    c->employees[j] = temp;
                }
            }
        }
    }
void sort(Company *c) {
        int n;
        cout << "1: Sort by ID" << endl;
        cout << "2: Sort by Salary" << endl;
        cout << "3: Sort by Date" << endl;
        cin >> n;
        switch (n) {
            case 1:
                // statements
                sort_id(c);
                break;
            case 2:
                // statements
                sort_salary(c);
                break;
            default:
                // statements if no case matches
                sort_date(c);
        }
    }

void init(Company *c) {
    c->employees[c->num].id = 4;
    c->employees[c->num].salary = 10500;
    c->employees[c->num].date.day = 15;
    c->employees[c->num].date.month = 1;
    c->employees[c->num].date.year = 2012;
    (c->num)++;
    c->employees[c->num].id = 2;
    c->employees[c->num].salary = 20550;
    c->employees[c->num].date.day = 15;
    c->employees[c->num].date.month = 2;
    c->employees[c->num].date.year = 2017;
    (c->num)++;
    c->employees[c->num].id = 3;
    c->employees[c->num].salary = 10500;
    c->employees[c->num].date.day = 20;
    c->employees[c->num].date.month = 2;
    c->employees[c->num].date.year = 2021;
    (c->num)++;
    c->employees[c->num].id = 1;
    c->employees[c->num].salary = 30100;
    c->employees[c->num].date.day = 20;
    c->employees[c->num].date.month = 2;
    c->employees[c->num].date.year = 2021;
    (c->num)++;
}
int main() {
    Company comp;
    comp.num = 0;
    init(&comp);
 

    while(true){
        listOptions();
        int opt;
        cin >> opt;
        if (opt == 0) {
            cout << "Bye!\n";
            break;
        } else if (opt == 1) {
            hire(&comp);
        } else if (opt == 2) {
            show(&comp);
        } else if (opt == 3) {
            transfer(&comp);
        } else if (opt == 4) {
            sort(&comp);
        }
        
        cout<<endl;
    }
    
    return 0;
    
}
