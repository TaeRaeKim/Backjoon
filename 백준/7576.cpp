#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define MAX 1001

int N, M, ans;
int arr[MAX][MAX];
queue<pii> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		pii p = q.front(); q.pop();

		int ni, nj;
		for (int i = 0; i < 4; i++) {
			ni = p.first + dx[i];
			nj = p.second + dy[i];
			if (ni >= 0 && ni <= N - 1 && nj >= 0 && nj <= M - 1 && arr[ni][nj] == 0) {
				arr[ni][nj] = arr[p.first][p.second] + 1;
				q.push(make_pair(ni, nj));
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				ans = 0;
				cout << -1;
				return 0;
			}
			ans = max(ans, arr[i][j]);
		}
	}
	cout << (ans - 1) << '\n';
	return 0;
}
