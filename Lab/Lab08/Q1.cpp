#include <iostream>
#include <cstring>
using namespace std;
char* deleteStr(char* str, char delete_char) {
	int len = strlen(str);
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] != delete_char)	cnt++;
	}

	char* r = new char[cnt + 1];
	for(int i = 0, j = 0; i < len; i++) {
		if (str[i] != delete_char) {
			r[j] = str[i];
			j++;
		}
	}
	r[cnt] = '\0';
	return r;
}
int main() {
	char str[1000];
	char delete_char;
	cout<<"Enter the input string: \n";
	cin.getline(str, 1000);
	cout << "Enter the input delete_char: \n";
	cin >> delete_char;

	char* res = deleteStr(str, delete_char);
	cout <<"The modified string is: " << res << endl;

	delete[] res;
	return 0;
}