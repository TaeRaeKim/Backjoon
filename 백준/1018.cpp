// 문제 시작시간 : 1200
// 풀이 완료시간 : 1255
// 스스로 풀었는가 : O

#include <iostream>
using namespace std;

#define A 8
int solve(int, int);

char arr[50][50];
int N, M;
int ans = 64;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//input
	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];

	//solve
	int t;
	for (int i = 0; i <= N - A; i++) {
		for (int j = 0; j <= M - A; j++) {
			t = solve(i, j);
			if (ans > t)ans = t;
		}
	}

	//output
	cout << ans;

	return 0;
}

int solve(int n, int m) {
	char c = arr[n][m];
	int ans[2] = {};

	for (int k = 0; k < 2; k++) {
		if (k == 0)c = arr[n][m];
		else c = arr[n][m] == 'W' ? 'B' : 'W';

		for (int i = 0; i < A; i++) {
			for (int j = i % 2; j < A; j += 2) {
				if (c != arr[n + i][m + j]) ans[k]++;
			}
		}

		for (int i = 0; i < A; i++) {
			for (int j = (i + 1) % 2; j < A; j += 2) {
				if (c == arr[n + i][m + j]) ans[k]++;
			}
		}
	}
	return min(ans[0], ans[1]);
}