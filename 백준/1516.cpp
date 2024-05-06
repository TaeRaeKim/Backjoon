#include <bits/stdc++.h>
using namespace std;

class Building {
private :
	list<Building*> next;
	int totalBuildTime, buildTime, indegree;
public:
	void addPrecede(Building* p) {
		next.push_back(p);
		p->indegree++;
	}
	void setBt(int bt) { buildTime = bt; };

	int getTbt() { return totalBuildTime; };
	void InitTbt() { totalBuildTime = buildTime; };

	int getIndegree() { return indegree; };

	void deleteEdge(queue<Building*>* q) {
		for (Building* t : next) {
			t->totalBuildTime = max(t->totalBuildTime, totalBuildTime + t->buildTime);
			t->indegree--;
			if (t->indegree == 0) q->push(t);
		}
	}
};

int N;
vector<Building> building(501);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1, t, j; i <= N; i++) {
		cin >> t;
		building[i].setBt(t);
		while (true) {
			cin >> j;
			if (j == -1) break;
			building[j].addPrecede(&building[i]);
		}
	}

	queue<Building*> q;
	for (int i = 1; i <= N; i++) {
		if (building[i].getIndegree() == 0) {
			building[i].InitTbt();
			q.push(&building[i]);
		}
	}
	while (!q.empty()) {
		Building* f = q.front(); q.pop();
		f->deleteEdge(&q);
	}

	for (int i = 1; i <= N; i++) cout << building[i].getTbt() << '\n';

	return 0;
}