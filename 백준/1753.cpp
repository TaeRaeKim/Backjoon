#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using pii= pair<int, int>;

bool compare(pii p, pii o) { return (p.second > o.second ? true : false); };

priority_queue<pii, vector<pii>, decltype(&compare)> pq(compare);
vector<unordered_map<int,int>> v(20001);
bool vis[20001];

int V, E, sp, s, t, w, A[20001];
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

	cin >> V >> E >> sp;

	for (int i = 0; i < E; i++) {
		cin >> s >> t >> w;
		if (v[s][t] == 0 || v[s][t] > w) v[s][t] = w;
	}

	pq.push(make_pair(sp, 0));
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		if (vis[p.first]) continue;
		vis[p.first] = true;
		A[p.first] = p.second;
		for (pii np : v[p.first]) {
			pq.push(make_pair(np.first, p.second + np.second));
		}
	}
	for (int i = 1; i <= V; i++) {
		if (i == sp) cout << "0\n";
		else cout << (A[i] == 0 ? "INF" : to_string(A[i])) << '\n';
	}	
	return 0;
}
