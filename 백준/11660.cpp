#include <bits/stdc++.h>
using namespace std;

int a[1025][1025];
int sum[1025][1025];
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
			sum[i][j] = sum[i][j-1] + a[i][j];
		}
	}

	int Answer;
	pair<int, int> s, e;
	for (int i = 0; i < M; i++) {
		Answer = 0;
		cin >> s.first >> s.second >> e.first >> e.second;

		for (int y = s.first; y <= e.first; y++) {
			Answer += sum[y][e.second] - sum[y][s.second - 1];
		}
		cout << Answer << '\n';
	}

	return 0;
}