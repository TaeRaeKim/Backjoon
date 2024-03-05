#include <bits/stdc++.h>
using namespace std;

int N;
bool arr[6561][6561];

void dfs(int i, int j, int N) {
	if (N == 1) {
		arr[i][j] = true;
		return;
	}

	for (int l = 0; l < 3; l++) {
		for (int m = 0; m < 3; m++) {
			if (l == 1 && m == 1) continue;
			dfs(i + l*(N/3), j + m*(N/3), N / 3);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	dfs(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << (arr[i][j] ? '*' : ' ');
		}
		cout << '\n';
	}
	return 0;
}