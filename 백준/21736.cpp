#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, ans;
pii sp;
char arr[601][601];
bool check[601][601];
int di[] = { -1, 0, 1, 0 }, dj[] = { 0, 1, 0, -1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin.ignore();
	string t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		for (int j = 0; j < M; j++) {
			arr[i][j] = t[j];
			if (arr[i][j] == 'I') sp.first = i, sp.second = j;
		}
	}

	queue<pii> q;
	check[sp.first][sp.second] = true;
	q.push(sp);

	while (!q.empty()) {
		pii t = q.front(); q.pop();
		if (arr[t.first][t.second] == 'P') ans++;

		for (int k = 0; k < 4; k++) {
			int ni = t.first + di[k], nj = t.second + dj[k];
			if (ni >= 0 && ni < N && nj >= 0 && nj < M &&
				!check[ni][nj] && arr[ni][nj] != 'X') {
				check[ni][nj] = true;
				q.push(make_pair(ni, nj));
			}
		}
	}
	if (ans > 0) cout << ans;
	else cout << "TT";

	return 0;
}