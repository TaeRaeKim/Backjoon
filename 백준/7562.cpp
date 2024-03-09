#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define MAX 301

int TC, l, ans;
vector<vector<int>> arr(MAX, vector<int>(MAX));

pii sp, ep;

int dx[8] = { -2,-2,-1, 1, 2, 2, 1,-1 };
int dy[8] = { -1, 1, 2, 2, 1,-1,-2,-2 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> l;
		cin >> sp.first >> sp.second;
		cin >> ep.first >> ep.second;

		queue<pii> q;
		for (int i = 0; i < l; i++) arr[i].assign(MAX, 0);

		arr[sp.first][sp.second] = 1;
		q.push(sp);

		while (!q.empty()) {
			pii t = q.front(); q.pop();
			if (t == ep) {
				ans = arr[t.first][t.second];
				break;
			}
			int ni, nj;
			for (int i = 0; i < 8; i++) {
				ni = t.first + dx[i], nj = t.second + dy[i];
				if (ni >= 0 && ni <= l-1 && nj >= 0 && nj <= l-1 && arr[ni][nj]==0) {
					arr[ni][nj] = arr[t.first][t.second] + 1;
					q.push(make_pair(ni, nj));
				}
			}
		}
		cout << ans-1 << '\n';
	}
	return 0;
}
