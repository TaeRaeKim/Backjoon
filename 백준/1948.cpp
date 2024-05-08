#include <bits/stdc++.h>
using namespace std;
using edge = pair<int, int>;
using vertex = pair<int, int>;

class City {
public:
	vector<edge> next;
	int indegree = 0;
	int arriveTime = 0;

	vector<edge> before;
	bool check;
};

int N, M, answer;
City city[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int s, e, t;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> t;
		city[e].indegree++;
		city[s].next.push_back(make_pair(t, e));

		city[e].before.push_back(make_pair(t, s));
	}
	cin >> s >> e;

	queue<int> q;
	city[s].arriveTime = 0;
	q.push(s);
	while (!q.empty()) {
		int i = q.front(); q.pop();

		for (edge n : city[i].next) {
			city[n.second].indegree--;
			if (city[n.second].arriveTime < city[i].arriveTime + n.first) {
				city[n.second].arriveTime = city[i].arriveTime + n.first;
			}
			if (city[n.second].indegree == 0) {
				q.push(n.second);
			}
		}
	}
	cout << city[e].arriveTime << '\n';

	queue<vertex> vq;
	vq.push(vertex(0, e));
	int count = 0;
	while (!vq.empty()) {
		int time = vq.front().first;
		int i = vq.front().second; vq.pop();

		for (edge n : city[i].before) {
			if (city[e].arriveTime == city[n.second].arriveTime + time + n.first) {
				count++;
				if (!city[n.second].check) {
					city[n.second].check = true;
					vq.push(make_pair(time + n.first, n.second));
				}
			}
		}
	}
	cout << count;

	return 0;
}