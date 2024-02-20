#include <bits/stdc++.h>
using namespace std;

vector<long long int> dp(1000001);
vector<long long int> ans(1000001);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp.resize(1000001);
	dp[1] = 1;
	ans[1] = 1;
	int T, N;

	fill(dp.begin(), dp.end(), 1);
	for (int i = 2; i <= 1000000; i++) {
		for (int j = 1; i * j <= 1000000; j++) {
			dp[i * j] += i;
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		ans[i] = ans[i - 1] + dp[i];
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << ans[N] << "\n";
	}
}