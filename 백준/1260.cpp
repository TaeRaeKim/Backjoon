#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1001
#define MAX_M 10001

int N, M, V, a, b, t;
vector<set<int>> m(MAX_N);
vector<bool> check(MAX_N);
queue<int> q;

void dfs(int);
void bfs(int);
void init();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		m[a].insert(b);
		m[b].insert(a);
	}

	dfs(V);	

	init();

	bfs(V);

	return 0;
}

void dfs(int v) {
	cout << v << " ";
	check[v] = true;

	for (int i : m[v]) {
		if (!check[i]) dfs(i);
	}
}
void bfs(int v) {
	check[v] = true;
	q.push(v);
	while (!q.empty()) {
		t = q.front();
		cout << t << " ";
		q.pop();
		for (int i : m[t]) {
			if (!check[i]) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

void init() { check.assign(MAX_N, 0); cout << '\n'; }