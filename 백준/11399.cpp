#include <bits/stdc++.h>
using namespace std;

int N, V;
vector<pair<int, int>> vec(1000);

bool compare(pair<int, int> p, pair<int, int> o) {
	return (p.second < o.second ? true : false);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> V;
		vec[i] = make_pair(i, V);
	}

	sort(vec.begin(), vec.begin()+N, compare);

	int sum = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		sum += vec[i].second;
		ans += sum;
	}

	cout << ans;

	return 0;
}