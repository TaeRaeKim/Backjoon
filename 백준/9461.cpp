#include <bits/stdc++.h>
using namespace std;

long long int arr[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Tc, n;
	cin >> Tc;
	arr[1] = 1;	arr[2] = 1;	arr[3] = 1;
	for (int tc = 0; tc < Tc; tc++) {
		cin >> n;
		if (arr[n] != 0) {
			cout << arr[n] << '\n';
			continue;
		}
		for (int i = 4; i <= n; i++) {
			arr[i] = arr[i - 2] + arr[i - 3];
		}
		cout << arr[n] << '\n';
	}

	return 0;
}