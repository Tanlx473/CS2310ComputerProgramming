//
//  main.cpp
//  q3
//
//  Created by Jeremy Tan on 2025/10/21.
//

#include <iostream>
using namespace std;

int stringCompare (char *s1, char *s2) {
  while(*s1 != '\0' && *s2 != '\0') {
    if(*s1 > *s2) {
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
  char s[15][1000];
  char *ss[15];

  int n;
  cout << "Enter the number of the strings:" << endl;
  cin >> n;
  cout << "Enter the contents of each string:"<< endl;
  for(int i = 0; i < n; i++){
      cin>>s[i];
      ss[i] = &s[i][0];
  }

      for(int i = 0; i < n; i++){
          for(int j = i+1; j < n; j++){
              if(stringCompare(ss[i],ss[j])>0){
                  char *temp = ss[i];
                  ss[i] = ss[j];
                  ss[j] = temp;

              }
          }
      }

      cout << "The sorted strings are:" << endl;
      for(int i = 0; i < n; i++){
          cout<<ss[i]<<endl;
      }

      return 0;
}
