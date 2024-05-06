#include <iostream>
#include <queue>
#define LARGE 987654321

using namespace std;

int N;
int map[125][125];
int visit[125][125];
int cost[125][125];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

typedef pair<int, int> pii;
typedef pair<int, pii> pos;

bool isValid(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= N) return false;
	return true;
}
int main() {

	int tc = 1;

	while (true) {
		cin >> N;

		if (N == 0) {
			break;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				visit[i][j] = 0;
				cost[i][j] = LARGE;
			}
		}

		pos start = pos(map[0][0], pii(0, 0));
		priority_queue<pos, vector<pos>, greater<pos>> q;

		q.push(start);
		cost[0][0] = map[0][0];

		while (!q.empty()) {
			pos now = q.top();

			int c = now.first;
			int y = now.second.first;
			int x = now.second.second;

			visit[y][x] = 1;
			q.pop();

			if (y == N - 1 && x == N - 1) {
				cout << "Problem " << tc << ": " << c << '\n';
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!isValid(ny, nx)) continue;
				int nc = c + map[ny][nx];

				if (visit[ny][nx] == 0 && nc < cost[ny][nx]) {
					cost[ny][nx] = nc;
					q.push(pos(nc, pii(ny, nx)));
				}
			}
		}
		tc++;
	}
	return 0;
}