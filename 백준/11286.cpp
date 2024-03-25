#include <bits/stdc++.h>
using namespace std;

bool compare(int o, int t) {
	if (abs(o) > abs(t)) return true;
	else if (abs(o) == abs(t)) return (o > t) ? true : false;
	return false;
}
priority_queue<int, vector<int>, decltype(&compare)> pq(compare);
void insert(int v) { pq.push(v); }

void print() {
	if (pq.empty()) cout << '0' << '\n';
	else {
		cout << pq.top() << '\n';
		pq.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, t;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t == 0) print();
		else insert(t);
	}
	return 0;
}