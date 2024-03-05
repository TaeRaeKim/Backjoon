#include <bits/stdc++.h>
using namespace std;

bool arr[1024 * 3 + 1][1024 * 6 + 1];
void dfs(int i, int j, int k) {
	if (k == 0) {
		arr[i - 3][j + 2] = true;
		arr[i - 2][j + 1] = true; arr[i - 2][j + 3] = true;
		for (int l = 0; l < 5; l++) arr[i - 1][j + l] = true;
		return;
	}
	dfs(i - 3 * pow(2, k - 1), j + 3 * pow(2, k - 1), k - 1);
	dfs(i, j, k - 1);
	dfs(i, j + 3 * pow(2, k), k - 1);

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int k = N / 3;
	k = log2(k);
	dfs(N, 0, k);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++) {
			if (arr[i][j]) cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}