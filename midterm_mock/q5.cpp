#include <iostream>
#include <set>
#include <string>
using namespace std;

class book
{
   private:
   char id;
   string subject;
   int price;
   int month;
   int day;

   public:
   char getID()
   {
      return id;
   }
   string getSub()
   {
      return subject;
   }
   int getPrice()
   {
      return price;
   }
   int getMonth()
   {
      return month;
   }
   int getDay()
   {
      return day;
   }
   void set(char i, string s, int p, int m, int d)
   {
      id = i;
      subject = s;
      price = p;
      month = m;
      day = d;
   }

};

int main()
{
   int N = 10;
   book bArr[N];
   bArr[0].set('A', "Math", 80, 2, 20);
   bArr[1].set('B', "Computer Science", 60, 3, 16);
   bArr[2].set('C', "Biology", 150, 2, 23);
   bArr[3].set('D', "Computer Science", 80, 10, 5);
   bArr[4].set('E', "Physics", 200, 11, 2);
   bArr[5].set('F', "Psychology", 300, 1, 1);
   bArr[6].set('G', "Business", 240, 5, 30);
   bArr[7].set('H', "Physics", 240, 6, 24);
   bArr[8].set('I', "Chemistry", 160, 8, 17);
   bArr[9].set('J', "Biology", 80, 5, 8);

   cout << "The list of the books:\n";
   for (int i = 0; i < 10; i++)
   {
      cout << "Book " << bArr[i].getID() << ": "
           << bArr[i].getSub() << " "
           << bArr[i].getMonth() << "-"
           << bArr[i].getDay() << endl;
   }

   //Sorting
   for (int i = 0; i < 10; i++)
   {
      for (int j = 0; j < 10; j++)
      {
         if (bArr[i].getPrice() < bArr[j].getPrice())
         {
            book temp;
            temp = bArr[i];
            bArr[i] = bArr[j];
            bArr[j] = temp;
         }
      }
   }

   cout <<endl<< "The list of sorted books:\n";
   for (int i = 0; i < 10; i++)
   {
      cout <<  bArr[i].getID() << "("
           << bArr[i].getPrice() << ","
           << bArr[i].getSub() << ")"
           << endl;
   }
   return 0;
}