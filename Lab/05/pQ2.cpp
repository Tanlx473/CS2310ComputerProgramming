//
// Created by Jeremy Tan on 2025/10/25.
//
#include <iostream>
#include <string>
using namespace std;
void dateOf2017(string date) {
    string month, day;
    month = date.substr(0,2);
    day = date.substr(3,2);
    int monthNum = 10*(month[0] - '0') + (month[1] - '0');
    int dayNum = 10*(day[0] - '0') + (day[1] - '0');
    int dayOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int totalDays = 0;
    for (int i = 0; i < monthNum - 1; i++) {
        totalDays += dayOfMonth[i];
    }

    totalDays += dayNum ;
    totalDays -= 1;
    string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday"};

    int weekday;
    weekday = totalDays % 7;
    cout << "2017-" << date << " is " << week[weekday] << endl;
}
int main() {
    string date;
    cout<<"Enter the date in 2017: \n";
    cin>>date;
    dateOf2017(date);
}