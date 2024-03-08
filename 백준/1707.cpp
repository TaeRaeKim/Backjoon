#include <bits/stdc++.h>
using namespace std;

#define MAX_V 20001
#define MAX_E 200001

int K, V, E, a, b;

vector<list<int>> vec(MAX_V);
vector<int> check(MAX_V);

bool solve(int v, int vs) {
	check[v] = vs;
	for (int i : vec[v]) {
		if (check[i] == 0) {
			if (!solve(i, (vs == 1) ? 2 : 1)) return false;
		}
		else if (check[v] == check[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K;
	for (int k = 0; k < K; k++) {
		cin >> V >> E;

		for (int i = 1; i <= V; i++) {
			vec[i].clear();
			check[i] = 0;
		}		

		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		bool ans = true;
		for (int i = 1; i <= V; i++) {
			if (check[i] == 0) {
				if (!solve(i, 1)) {
					ans = false;
					break;
				}
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
	return 0;
}