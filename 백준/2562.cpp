#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 1;
	int arr[10] = {};
	int i;
	for (int n = 0; n < 3; n++) {
		cin >> i;
		num *= i;
	}
	while (num != 0) {
		arr[num % 10]++;
		num /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}