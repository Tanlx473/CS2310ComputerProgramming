//
//  main.cpp
//  Lab02_Q3
//
//  Created by Jeremy Tan on 2025/9/9.
//

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    double a, b, c;
    cout << "Enter the value of a, b and c for quadratic equation: " << endl;
    cin >> a >> b >> c;

    // delta
    double del= b * b - 4 * a * c;

    cout<<fixed<<setprecision(1);
    
    if (del >= 0){
        double root1, root2;
        root1 = (-b + sqrt(del))/ (2 * a);
        root2 = (-b - sqrt(del)) / (2 * a);
        cout << "The Quadratic Equation has two Real roots: ";
        cout << root1<< " and " <<  root2<<endl;
    }
    else{
        double root_r, root_i;
        root_r = -b / (2 * a);
        root_i = sqrt(-del)/ (2 * a);
        cout << "The Quadratic Equation has two Complex roots: ";
        cout << root_r<<"+"<<root_i<<"i" << " and " <<  root_r <<"-"<<root_i<<"i" << endl;
    }
    return 0;
}

//# Use Complex Header file
//#include <iostream>
//#include <complex>
//#include <iomanip>
//using namespace std;
//
//int main() {
//    double a, b, c;
//    cout << "Enter the value of a, b and c for quadratic equation: " << endl;
//    cin >> a >> b >> c;
//    
//    // delta
//    double del= b * b - 4 * a * c;
//
//    // Use complex numbers represent roots:
//    complex<double> root1 = (-b + sqrt(complex<double>(del))) / (2.0 * a);
//    complex<double> root2 = (-b - sqrt(complex<double>(del))) / (2.0 * a);
//
//    cout<<fixed<<setprecision(1);
//    if (del >= 0){
//        cout << "The Quadratic Equation has two Real roots: ";
//        cout << root1.real()<< " and " <<  root2.real()<<endl;
//    }
//    else{
//        cout << "The Quadratic Equation has two Complex roots: ";
//        cout << root1.real()<<"+"<<root1.imag()<<"i" << " and " <<  root2.real()<<"+"<<root2.imag()<<"i" << endl;
//    }
//    return 0;
//}

