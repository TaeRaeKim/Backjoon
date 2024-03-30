#include <bits/stdc++.h>
using namespace std;
#define MAX 100000 +1

class Node {
public:
	list<Node*> linked;
	int parent;
	int index;
};
int N;
vector<bool> check(MAX);
vector<Node> node(MAX);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	node.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		node[i].index = i;
	}

	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		node[a].linked.push_back(&node[b]);
		node[b].linked.push_back(&node[a]);
	}
	node[1].parent = 1;

	queue<Node*> q;
	check[1] = true;
	q.push(&node[1]);

	while (!q.empty()) {
		Node* t = q.front(); q.pop();
		for (Node* tNode : t->linked) {
			if (tNode->parent == 0) {
				tNode->parent = t->index;
				q.push(tNode);
			}
		}
	}

	for (int i = 2; i <= N; i++) cout << node[i].parent << "\n";

	return 0;
}