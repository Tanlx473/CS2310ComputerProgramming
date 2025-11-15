//
//  main.cpp
//  Lab02_Q2
//
//  Created by Jeremy Tan on 2025/9/9.
//

#include <iostream>
using namespace std;
int main() {
    // get length of each sides from input
    int a,b,c;
    cin>>a>>b>>c;
    if (a<=0 || b<=0 || c<=0 ){
        cout<<"Impossible"<<endl;
        return 0;
    }
    if (a == b && b == c){
        cout<<"Equilateral"<<endl;
        return 0;
    }
    
    if(a == b || b == c || c == a){
        cout<<"Isosceles"<<endl;
        return 0;
    }
    
    if(a+b>c && a+c>b && b+c>a ){
        cout<<"Scalene"<<endl;
        return 0;
    }
    else{
        cout<<"Impossible"<<endl;
        return 0;
    }
    return 0;
}



//#include <iostream>
//using namespace std;
//
//string whichtriangle(int a,int b,int c){
//    if (a<=0 || b<=0 || c<=0 ){
//        return "Impossible";
//    }
//    if (a == b && b == c){
//        return "Equilateral";
//    }
//    
//    if(a == b || b == c || c == a){
//        return "Isosceles";
//    }
//    
//    if(a+b>c && a+c>b && b+c>a ){
//        return "Scalene";
//    }
//    else{
//        return "Impossible";
//    }
//}
//
//int main() {
//    // get length of each sides from input
//    int x,y,z;
//    cin>>x>>y>>z;
//    cout<<whichtriangle(x,y,z)<<endl;
//    return 0;
//}
