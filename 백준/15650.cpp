#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[9];
void solve(int i, int s) {
	for (; i <= N - K + s; i++) {
		arr[s] = i;

		if (s == K) {
			for (int m = 1; m <= K; m++) cout << arr[m] << " ";
			cout << endl;
			continue;;
		}
		solve(i + 1, s + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	solve(1, 1);
	return 0;
}