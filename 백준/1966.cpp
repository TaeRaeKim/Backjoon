#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int Tc, N, M, t;
pii question;
int main() {

	cin >> Tc;
	for (int tc = 0; tc < Tc; tc++) {
		priority_queue<int, vector<int>, less<int>> pq;
		queue<pii> q;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> t;
			if (i == M) question = make_pair(t, i);
			pq.push(t);
			q.push(make_pair(t, i));
		}
		int ans = 0;
		while (!q.empty()) {
			if (q.front().first == pq.top()) {
				ans++;
				if (question.first == q.front().first && question.second == q.front().second) {
					cout << ans << '\n';
					break;
				}
				pq.pop(); q.pop();				
			}
			else {
				q.push(q.front()); q.pop();
			}
		}
	}

	return 0;
}