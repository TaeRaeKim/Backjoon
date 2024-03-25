#include <bits/stdc++.h>
#define MAX 1000

using namespace std;
using pii = pair<int, int>;
using pbpii = pair<bool, pii>;

//북동남서
int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };

int N = 0, M = 0;

bool arr[MAX][MAX];
int check[2][MAX][MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << pow(2, 2);

	cout.tie(nullptr);

	cin >> N >> M;
	cin.ignore();

	string str;
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j] - '0';
			check[0][i][j] = MAX * MAX;
			check[1][i][j] = MAX * MAX;
		}
	}

	queue<pbpii> q;
	check[0][0][0] = 1;

	q.push(make_pair(true, make_pair(0, 0)));
	while (!q.empty()) {
		bool canBreak = q.front().first;
		int i = q.front().second.first;
		int j = q.front().second.second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ni = i + di[k], nj = j + dj[k];

			if (ni >= 0 && ni < N && nj >= 0 && nj <= M) {

				if (canBreak) { //부술수 있을때는
					if (arr[ni][nj] == 1 && check[1][ni][nj] > check[0][i][j] + 1) {
						check[1][ni][nj] = check[0][i][j] + 1;
						q.push(make_pair(false, make_pair(ni, nj)));
					}
					else if (arr[ni][nj] == 0 && check[0][ni][nj] > check[0][i][j] + 1) {
						check[0][ni][nj] = check[0][i][j] + 1;
						q.push(make_pair(true, make_pair(ni, nj)));
					}
				}
				else {
					if (arr[ni][nj] == 0 && check[1][ni][nj] > check[1][i][j] + 1) {
						check[1][ni][nj] = check[1][i][j] + 1;
						q.push(make_pair(false, make_pair(ni, nj)));
					}
				}
			}
		}
	}
	int ans = min(check[0][N - 1][M - 1], check[1][N - 1][M - 1]);
	cout << (ans == MAX * MAX ? -1 : ans);

	return 0;
}