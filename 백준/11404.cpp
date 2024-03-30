#include <bits/stdc++.h>
using namespace std;

int N, M, sp, ep, v;
int arr[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = 10000001;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> sp >> ep >> v;
		arr[sp][ep] = min(arr[sp][ep], v);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) arr[i][j] = 0;
			cout << (arr[i][j] == 10000001 ? 0 : arr[i][j]) << " ";
		}
		cout << '\n';
	}

	return 0;
}