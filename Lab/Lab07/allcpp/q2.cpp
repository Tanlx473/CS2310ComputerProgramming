//
// q2
// Created by Jeremy Tan on 2025/10/21.
//

#include <iostream>
using namespace std;
int stringCompare(char *s1, char *s2){
  while(*s1 != '\0' && *s2 != '\0'){
    if(*s1 > *s2){
      return 1;
    }
    else if(*s1 < *s2){
      return -1;
    }
    else{
      s1++;
      s2++;
    }


}
  if (*s1 == '\0' && *s2 == '\0') {
    return 0;
  } else if (*s1 == '\0') {
    return -1;
  } else {
    return 1;
  }
}


int main(){
    char s1[1000];
    char s2[1000];
  cout << "Enter the frist string: " << endl;
  cin>>s1;
  cout << "Enter the second string:" << endl;
  cin>>s2;

  int r = stringCompare(s1, s2);
  if (r == 1) {
    cout << "The first string is larger." << endl;
  } else if (r == -1) {
    cout << "The second string is larger." << endl;
  } else {
    cout << "The two strings are equal." << endl;
  }
  return 0;
}
