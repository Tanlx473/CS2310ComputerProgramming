#include <iostream>
using namespace std;

// 计算数字和
int sum_of_digits(int x) {
	int sum = 0;
	while (x != 0) {
		sum += x % 10;
		x = x / 10;
	}
	return sum;
}

// 冒泡排序函数 —— 使用指针参数
void bubble(int *arr, int *out, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {  // 从小到大排序
				// 交换 arr
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				// 同步交换 out
				temp = out[j];
				out[j] = out[j + 1];
				out[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n;
	int arr[10];
	int out[10];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		out[i] = sum_of_digits(arr[i]);
	}

	bubble(arr, out, n);

	cout << "After sorting:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " (sum=" << out[i] << ")\n";
	}

	return 0;
}
