#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	double sum = 0;
	int max = 0;
	int arr[1000];
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr[i] = temp;
		if (max < temp) max = temp;
	}
	for (int i = 0; i < N; i++) {
		sum = sum + ((double)arr[i] / max * 100);
	}
	cout << fixed;
	cout.precision(3);
	cout << sum / N;

	return 0;
}
