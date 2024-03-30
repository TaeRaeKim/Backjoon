#include <bits/stdc++.h>
using namespace std;

int N, arr[101][101];
int ans[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			ans[i][j] = arr[i][j] == 1 ? 1 : 10001 ;
		}
	}
	
	for (int m = 1; m <= N; m++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				ans[i][j] = min(ans[i][j], ans[i][m] + ans[m][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << (ans[i][j] < 10001 ? 1: 0) << " ";
		}
		cout << '\n';
	}

	return 0;
}