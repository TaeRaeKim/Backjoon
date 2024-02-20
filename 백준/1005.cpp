#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, K, W;
vector<int> t(1001, 0);
vector<int> sum_t(1001, -1);
map<int, vector<int>> m;

int find(int n) {
	if (sum_t[n] != -1) {
		return sum_t[n];
	}
	// n건물을 짓기위한 건물 k들
	// k들중 가장 오래 시간이 필요한 건물의 시간 l
	sum_t[n] = 0;
	for (int k : m[n]) {
		sum_t[n] = max(sum_t[n], find(k));
	}
	
	return sum_t[n]+= t[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int Tc;
	cin >> Tc;

	for (int tc = 0; tc < Tc; tc++) {
		cin >> N >> K;

		sum_t.assign(N+1, -1);
		for (int i = 1; i <= N; i++) m[i].clear();

		for (int n = 1; n <= N; n++) {
			cin >> t[n];
		}
		int x, y;
		for (int k = 0; k < K; k++) {
			cin >> x >> y;
			m[y].push_back(x);
		}
		cin >> W;
		for (int i = 1; i <= N; i++) {
			if (m[i].empty()) sum_t[i] = t[i];
		}
		cout << find(W) << '\n';
	}
	return 0;
}
