#include <bits/stdc++.h>
using namespace std;
int N, M, sp, ep;
class Node {
public: int nexts;
	  int upDown;
	  int distance;
	  int index;
};

queue<int> q;
Node node[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1,j=6; i <= 100; i++) {
		if (i >= 95) --j;
		node[i].index = i;
		node[i].nexts = j;
		node[i].distance = 100;
		
	}
	
	for (int i = 0; i < N; i++) {
		cin >> sp >> ep;
		node[sp].upDown = ep;
	}

	for (int i = 0; i < M; i++) {
		cin >> sp >> ep;
		node[sp].upDown = ep;
	}

	node[1].distance = 0;
	q.push(1);

	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (node[t].upDown > 0) {
			node[node[t].upDown].distance = node[t].distance;
			q.push(node[t].upDown);
			continue;
		}
		for (int i = 1; i <= node[t].nexts; i++) {
			if (node[t + i].distance > node[t].distance + 1) {
				node[t + i].distance = node[t].distance + 1;
				q.push(t + i);
			}
		}
	}
	cout << node[100].distance;

	return 0;
}
