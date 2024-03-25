#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Node { public:	list<pair<int, int>> child; };
int N, M, X, sp, ep, v;
vector<Node> node;

int SD(int origin, int dest);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> X;

	node.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> sp >> ep >> v;
		node[sp].child.push_back(make_pair(ep, v));
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, SD(i, X) + SD(X, i));
	}
	cout << ans;

	return 0;
}

int SD(int origin, int dest) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> check(N+1);
	pq.push(make_pair(0, origin));

	while (!pq.empty()) {
		int dinstance = pq.top().first;
		int n = pq.top().second; pq.pop();
		if (check[n]) continue;

		check[n] = true;
		if ( n == dest) return dinstance;

		for (pair<int, int> p : node[n].child) {
			if(!check[p.first])
				pq.push(make_pair(dinstance + p.second, p.first));
		}
	}
}