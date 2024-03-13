#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define MAX 100

vector<vector<char>> arr(MAX, vector<char>(100));
vector<vector<char>> temp(MAX, vector<char>(100));
vector<vector<int>> check(MAX);

int di[4] = {-1, 1, 0 ,0};
int dj[4] = { 0, 0, -1, 1 };

int N;
int Ans[2] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
		}
	}
	

	queue<pii> q;
	int ni, nj;
	int count = 1;
	for (int i = 0; i < N; i++) check.assign(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				check[i][j] = count;
				q.push(pii(i, j));
				while (!q.empty()) {
					pii t = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						ni = t.first + di[k];
						nj = t.second + dj[k];
						if (ni >= 0 && ni < N && nj >= 0 && nj < N
							&& arr[ni][nj] == arr[t.first][t.second] && check[ni][nj] == 0) {
							check[ni][nj] = count;
							q.push(pii(ni, nj));
						}
					}
				}
				count++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Ans[0] = max(Ans[0], check[i][j]);
		}
	}

	for (int i = 0; i < N; i++) check.assign(N, vector<int>(N));
	count = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				check[i][j] = count;
				q.push(pii(i, j));
				while (!q.empty()) {
					pii t = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						ni = t.first + di[k];
						nj = t.second + dj[k];
						if (ni >= 0 && ni < N && nj >= 0 && nj < N
							&& ((arr[ni][nj] == arr[t.first][t.second]) || (arr[ni][nj] == 'R' && arr[t.first][t.second] == 'G') || (arr[ni][nj] == 'G' && arr[t.first][t.second] == 'R'))
							&& check[ni][nj] == 0) {
							check[ni][nj] = count;
							q.push(pii(ni, nj));
						}
					}
				}
				count++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Ans[1] = max(Ans[1], check[i][j]);
		}
	}

	cout << Ans[0] << " " << Ans[1];


	return 0;
}