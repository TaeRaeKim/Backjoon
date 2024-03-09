#include <bits/stdc++.h>
using namespace std;

#define MAX 26

int N, maxi;
int arr[MAX][MAX];
bool check[MAX][MAX];
queue<pair<int, int>> q;
multiset<int> ms;

int ans[MAX * MAX / 2 + 1];


void giveNum(pair<int, int>, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	char ch;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			arr[i][j] = (ch == '1' ? 1 : 0);
		}
	}

	int c = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0 && arr[i][j] == 1) {
				check[i][j] = true;
				arr[i][j] = c;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					pair<int, int> p = q.front();
					q.pop();
					if (p.first - 1 >= 0		&& !check[p.first - 1][p.second] && arr[p.first - 1][p.second]) giveNum(make_pair(p.first - 1, p.second), c);
					if (p.first + 1 <= N - 1	&& !check[p.first + 1][p.second] && arr[p.first + 1][p.second]) giveNum(make_pair(p.first + 1, p.second), c);
					if (p.second - 1 >= 0		&& !check[p.first][p.second - 1] && arr[p.first][p.second - 1]) giveNum(make_pair(p.first, p.second - 1), c);
					if (p.second + 1 <= N - 1	&& !check[p.first][p.second + 1] && arr[p.first][p.second + 1]) giveNum(make_pair(p.first, p.second + 1), c);
				}
				c++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[arr[i][j]]++;
			maxi = max(maxi, arr[i][j]);
		}
	}
	cout << maxi << '\n';
	for (int i = 1; i <= maxi; i++) ms.insert(ans[i]);
	for(int i : ms) cout << i << '\n';

	return 0;
}

void giveNum(pair<int, int> next, int c) {
	arr[next.first][next.second] = c;
	check[next.first][next.second] = true;
	q.push(next);
}