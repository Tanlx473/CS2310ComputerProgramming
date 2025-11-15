//
//  main.cpp
//  lab06_q1
//
//  Created by Jeremy Tan on 2025/10/18.
//

#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;
    double area;

public:
    Triangle() {
        side1 = side2 = side3 = 0;
        area = 0;
    }

    Triangle(double a, double b, double c) {
        side1 = a;
        side2 = b;
        side3 = c;
        computeArea();
    }

    void setSides(double a, double b, double c) {
        side1 = a;
        side2 = b;
        side3 = c;
        computeArea();
    }

    void computeArea() {
        double s = (side1 + side2 + side3) / 2.0;
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double getArea() {
        return area;
    }
};

int main() {
    Triangle tri1;
    cout << "Area of Triangle (i.e. triangle1): " << tri1.getArea() << endl;

    Triangle tri2(3, 4, 5);
    cout << "Area of Triangle (i.e. triangle2 with sides 3, 4 and 5): " << tri2.getArea() << endl;

    double a, b, c;
    cout << "Enter New Sides for Triangle:" << endl;
    cin >> a >> b >> c;
    tri1.setSides(a, b, c);
    cout << "Area of Triangle: " << tri1.getArea() << endl;

    return 0;
}
