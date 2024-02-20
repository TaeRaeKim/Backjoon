#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr(9);
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 9-1; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = 101;
				arr[j] = 101;
				i = 10;
				j = 10;
				break;
			}
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << "\n";
	}

}