#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

int N, x, y;
priority_queue<pos, vector<pos>, greater<pos>> pq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		pq.push(pos(y, x));
	}

	while (!pq.empty()) {
		cout << pq.top().second << " " << pq.top().first << '\n';
		pq.pop();
	}

	return 0;
}