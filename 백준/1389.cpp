#include <bits/stdc++.h>
using namespace std;

class Node {
public :
	int index;
	list<pair<Node*, int>> friends;
};

int N, M, a, b, ans[101];
vector<Node> boj(101);

int solve(int n) {
	int result[101] = { 0, };
	bool check[101] = { 0, };

	queue<pair<Node*, int>> q;
	check[n] = true;

	q.push(make_pair(&boj[n], 0));

	pair <Node*, int> t;
	while (!q.empty()) {
		t = q.front(); q.pop();
		result[t.first->index] = t.second;

		for (pair <Node*, int> i : t.first->friends) {
			if (check[i.first->index]) continue;
			check[i.first->index] = true;
			q.push(make_pair(&boj[i.first->index], t.second + 1));
		}
	}
	for (int i = 1; i <= N; i++) {
		result[0] += result[i];
	}
	return result[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		boj[i].index = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		boj[a].friends.push_back(make_pair(& boj[b],1));
		boj[b].friends.push_back(make_pair(& boj[a],1));
	}
	ans[0] = ans[1] = solve(1);
	for (int i = 2; i <= N; i++) {
		ans[i] = solve(i);
		ans[0] = min(ans[0], ans[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (ans[0] == ans[i]) {
			cout << i;
			break;
		}
	}

	return 0;
}