#include <bits/stdc++.h>
using namespace std;
using route = pair<int, int>;
using Link = list<route>;

class PathPoint {
public:
	int cost;
	int index;
	bool isVisit[2];
	PathPoint(int c, int i) {
		cost = c;
		index = i;
		isVisit[1] = isVisit[0] = false;
	}
	PathPoint(int c, int i, bool v1, bool v2) {
		cost = c;
		index = i;
		isVisit[0] = v1;
		isVisit[1] = v2;
	}
};

bool compare(PathPoint oldPoint, PathPoint newPoint) {
	if (oldPoint.cost > newPoint.cost) return true;
	return false;
}

int N, M, v1, v2, sp, ep, cost;
int nextCost, nextIndex, color;
vector<Link> vec(801);
bool check[4][801][801];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> sp >> ep >> cost;
		vec[sp].push_back(route(cost, ep));
		vec[ep].push_back(route(cost, sp));
	}
	cin >> v1 >> v2;

	priority_queue<PathPoint, vector<PathPoint>, decltype(&compare)> pq(compare);
	pq.push(PathPoint(0, 1));

	while (!pq.empty()) {
		PathPoint pp = pq.top(); pq.pop();

		if (pp.index == v1) pp.isVisit[0] = true;
		else if (pp.index == v2) pp.isVisit[1] = true;

		if (pp.index == N) {
			if (pp.isVisit[0] && pp.isVisit[1]) {
				cout << pp.cost;
				return 0;
			}
		}

		for (route next : vec[pp.index]) {
			nextCost = pp.cost + next.first;
			nextIndex = next.second;
			if (!pp.isVisit[0] && !pp.isVisit[1]) color = 0;
			else if (pp.isVisit[0] && !pp.isVisit[1]) color = 1;
			else if (!pp.isVisit[0] && pp.isVisit[1]) color = 2;
			else  if (pp.isVisit[0] && pp.isVisit[1]) color = 3;

			if (!check[color][pp.index][nextIndex]) {
				check[color][pp.index][nextIndex] = true;
				pq.push(PathPoint(nextCost, nextIndex, pp.isVisit[0], pp.isVisit[1]));
			}
		}
	}

	cout << -1;
	return 0;
}