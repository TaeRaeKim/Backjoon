#include <bits/stdc++.h>
using namespace std;

int N, K, t;
vector<int> DP(10001);
vector<int> arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t <= K) arr.push_back(t);
	}
	DP[0] = 1;

	for (int t : arr) {
		if (t > K) continue;
		for (int i = 0; i <= K; i++) {
			if(i-t >=0) DP[i] = DP[i] + DP[i - t];
		}
	}
	cout << DP[K];

	return 0;
}