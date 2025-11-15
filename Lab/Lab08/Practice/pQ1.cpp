#include <iostream>
#include <cstring>
using namespace std;
char* replace (char* str, char* space){
	int str_len = strlen(str);
	int space_len = strlen(space);
	int cnt = 0;
	for (int i = 0;i < str_len; i++) {
		if (str[i] == ' ') {cnt++;}
	}

	char* re = new char[str_len + space_len * cnt + 1];
	int j = 0;
	for (int i = 0;i < str_len; i++) {
		if (str[i] == ' ') {
			strcpy(re + j, space);
			j += space_len;
		}
		else {
			re[j++] = str[i];
		}
	}
	re[j] = '\0';
	return re;
}

int main(){
	char input[1000], space[500];
	cout << "Enter the input string:\n";
	cin.getline(input, 1000);
	cout << "Enter the input space str:\n";
	cin.getline(space, 500);

	char* result = replace(input, space);
	cout << result << endl;
	delete[] result;
	return 0;
}