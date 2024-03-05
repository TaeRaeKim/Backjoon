#include <bits/stdc++.h>
using namespace std;

long long int arr[33];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	arr[1] = a % c;
	for (int i = 2; i <= 32; i++) {
		arr[i] = arr[i - 1] * arr[i - 1] % c;
	}
	long long int ans = 1;

	string bin = bitset<32>(b).to_string();

	cout << bin;
	for (int i = 32; i >= 1; i--) {
		if (bin[32 - i] == '1') ans = ans * arr[i] % c;
	}
	cout <<  ans << '\n';
	return 0;
}

