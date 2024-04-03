#include <bits/stdc++.h>
using namespace std;

int N, K;
int money[10];
int ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (K >= money[i]) {
			ans += K / money[i];
			K %= money[i];
		}
	}
	cout << ans;

	return 0;
}