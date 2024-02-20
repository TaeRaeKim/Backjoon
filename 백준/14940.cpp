#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> arr(1000, vector<int>(1000, -1));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<pair<int, int>> q;

	cin >> N >> M;
	int t = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> t;
			if (t == 2) {
				q.push(make_pair(i, j));
				arr[i][j] = 0;
			}
			else if (t == 0) {
				arr[i][j] = 0;
			}
		}
	}
	pair<int, int> p;
	int nextDistance;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		nextDistance = arr[p.first][p.second] + 1;
		if (p.first > 0 && arr[p.first - 1][p.second] == -1) {
			arr[p.first - 1][p.second] = nextDistance;
			q.push(make_pair(p.first - 1, p.second));
		}
		if (p.first < N - 1 && arr[p.first + 1][p.second] == -1) {
			arr[p.first + 1][p.second] = nextDistance;
			q.push(make_pair(p.first + 1, p.second));
		}
		if (p.second > 0 && arr[p.first][p.second - 1] == -1) {
			arr[p.first][p.second - 1] = nextDistance;
			q.push(make_pair(p.first, p.second - 1));
		}
		if (p.second < M - 1 && arr[p.first][p.second + 1] == -1) {
			arr[p.first][p.second + 1] = nextDistance;
			q.push(make_pair(p.first, p.second + 1));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}