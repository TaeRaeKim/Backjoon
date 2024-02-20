#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> q;
	vector<int> vec;
	int N, K;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int interval = 0;
	int v = 0;

	while (!q.empty()) {
		v = q.front();
		if (++interval != K) q.push(v);
		else {
			interval = 0;
			vec.push_back(v);
		}
		q.pop();
		
	}

	cout << "<";
	for (int i : vec) {
		if(i==vec.back()) cout << i;
		else cout << i << ", ";
	}
	cout << ">";

	return 0;
}
