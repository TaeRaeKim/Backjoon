#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int idx;
	map<Node*, int> nl;
	priority_queue<int, vector<int>, less<int>> pq;
};

bool v[10001];
int N;
Node node[10001];

int Ans = 0;

int dfs(Node* n, Node* parent) {
	v[n->idx] = true;
	if (n->nl.size() == 1 && n != &node[1]) {
		return n->nl.begin()->second;
	}

	for (pair<Node*, int> p : n->nl) {
		if(!v[p.first->idx])n->pq.push(dfs(p.first, n));
	}


	int lw; int t_ans = 0;
	if (!n->pq.empty()) {
		lw = n->pq.top();
		t_ans = lw;
		n->pq.pop();
		if (!n->pq.empty()) {
			t_ans += n->pq.top();
		}
	}
	else lw = 0;

	if (Ans < t_ans) Ans = t_ans;

	if (parent == nullptr) return lw;
	return lw + parent->nl[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int s, e, w;
	for (int i = 1; i <= N; i++) {
		node[i].idx = i;
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> s >> e >> w;
		node[s].nl.insert(make_pair(&node[e], w));
		node[e].nl.insert(make_pair(&node[s], w));
	}
	dfs(&node[1], nullptr);

	cout << Ans;

	return 0;
}
