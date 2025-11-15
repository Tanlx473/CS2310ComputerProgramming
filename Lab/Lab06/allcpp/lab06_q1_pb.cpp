//
//  main.cpp
//  lab06_q1_partB
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

void largerTriangle(Triangle t1, Triangle t2) {
    double area1 = t1.getArea();
    double area2 = t2.getArea();
    
    if (area1 == area2)
        cout << "The areas of the two triangles are identical." << endl;
    else if (area1 > area2)
        cout << "The Area " << area1 << " of Triangle 1 is larger than area " << area2 << " of Triangle 2." << endl;
    else
        cout << "The Area " << area2 << " of Triangle 2 is larger than area " << area1 << " of Triangle 1." << endl;
}

int main() {
//    Triangle tri1;
//    cout << "Area of Triangle (i.e. triangle1): " << tri1.getArea() << endl;
//
//    Triangle tri2(3, 4, 5);
//    cout << "Area of Triangle (i.e. triangle2 with sides 3, 4 and 5): " << tri2.getArea() << endl;

    double a1, b1, c1, a2, b2, c2;
    Triangle tri1, tri2;
    cout << "Enter New Sides for Triangle 1:" << endl;
    cin >> a1 >> b1 >> c1;
    tri1 = Triangle(a1, b1, c1);
    
    cout << "Enter New Sides for Triangle 2:" << endl;
    cin >> a2 >> b2 >> c2;
    tri2 = Triangle(a2, b2, c2);
    

    largerTriangle(tri1, tri2);
    return 0;
}
