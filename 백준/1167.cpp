#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int max, idx;
	map<Node*, int> child;
	priority_queue<int, vector<int>, greater<int>> pq;
};


int N;
Node node[100001];
bool v[100001];

void solve(Node*, Node*);
void print();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);
	cin >> N;
	
	int s, e, w;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		cin >> e;
		node[s].idx = s;
		while (e != -1) {
			cin >> w;
			node[s].child.insert(make_pair(&node[e], w));
			cin >> e;
		}
	}

	solve(&node[1], nullptr);
	int Ans = 0;
	int sum;
	for (int i = 1; i <= N; i++) {
		sum = 0;
		while (!node[i].pq.empty()) {
			sum += node[i].pq.top();
			node[i].pq.pop();
		}
		Ans = max(Ans, sum);
	}

	cout << Ans;
	//print();

	return 0;
}

void solve(Node* n, Node* parent) {
	if (v[n->idx]) {
		return;
	}
	v[n->idx] = true;
	for (pair<Node*, int> p : n->child) {
		if (p.first == parent) continue;
		solve(p.first, n);
	}

	for (pair<Node*, int> p : n->child) {
		if (p.first == parent) continue;
		n->max = max(n->max, p.first->max + p.second);
		n->pq.push(p.first->max + p.second);
		if (n->pq.size() > 2) n->pq.pop();
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		cout << "node : " << node[i].idx << endl;

		for (pair<Node*,int> c : node[i].child) {
			cout << "child : " << c.first->idx << endl;
		}
	}
}