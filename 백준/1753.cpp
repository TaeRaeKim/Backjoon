//못푼문제입니다.

#include <bits/stdc++.h>
using namespace std;

vector<map<int, int>> m(20001);
vector<int> answer(20001, -1);
int N, M;
int start;
int weight = 0;

void dfs(int, int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin >> start;
	int p1, p2, w;
	for (int i = 0; i < M; i++) {
		cin >> p1 >> p2 >> w;
		if (m[p1][p2] == 0) {
			m[p1][p2] = w;
			continue;
		}
		m[p1][p2] = (m[p1][p2] > w) ? w : m[p1][p2];
	}

	for (int i = 1; i <= N; i++) {
		for (pair<int, int> e : m[start]) {
			dfs(e.first, i, e.second);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (i == start) cout << "0\n";
		else if (answer[i] != -1) cout << answer[i] << '\n';
		else cout << "INF" << '\n';
	}
}

void dfs(int s, int e, int w) {
	if (answer[s] != -1 && answer[s] <= w) return;
	if (answer[e] != -1 && answer[e] <= w) return;

	//특정 노드를 방문했다면 가중치가 더 낮은것이기에 해당노드까지의 가중치 업데이트
	answer[s] = w;
	if (s == e) {
		//도착지라면 종료
		return;
	}
	for (pair<int, int> se : m[s]) {
		dfs(se.first, e, w + se.second);
	}
}
/*
* 
* 
		for (int j = 1; j <= N; j++) {
			if (m[i][j] > 0) {
				dfs(j, i, m[i][j]);
			}
		}


	for (int i = 1; i <= N; i++) {
		if (m[s][i] > 0) {
			dfs(i, e, w + m[s][i]);
		}
	}
*/