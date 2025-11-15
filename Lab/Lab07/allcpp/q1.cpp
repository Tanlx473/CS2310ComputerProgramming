//
// q1
// Created by Jeremy Tan on 2025/10/21.
//

#include <iostream>
using namespace std;

class Shape
{
  protected:
  int width;
  int height;

  public:
  void set(int w,int h)
  {
    width = w;
    height = h;
  }

};

class PointCost{
  public:
  int getCost(int a)
  {
    return 231 * a;
  }
};

class Rectangle:public Shape, public PointCost
{
  public:
  int getArea()
  {
    return width * height;
  }
  int  getPerimeter()
  {
    return 2 * (width + height);
  }
};

int main(){
  cout<<"Enter width:\n";
  int w;
  cin>>w;
  cout<<"Enter height:\n";
  int h;
  cin>>h;
  Rectangle r1;
  r1.set(w,h);
  int r1_a = r1.getArea();
  cout<<"Area is: "<<r1.getArea()<<endl;
  cout<<"Perimeter is: "<<r1.getPerimeter()<<endl;
  cout<<"Total paint cost is: "<<r1.getCost(r1_a)<<endl;
  return 0;
}
