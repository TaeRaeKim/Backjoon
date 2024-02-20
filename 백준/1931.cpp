#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	int s, e;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}
	sort(v.begin(), v.end());

	int count = 0;
	int time = 0;
	for (int i = 0; i < v.size(); i++) {
		if (time <= v[i].first && time <= v[i].second) {
			time = v[i].second;
			count++;
			continue;
		}

		if (time > v[i].first && time > v[i].second) {
			time = v[i].second;
		}
	}
	cout << count;
	return 0;
}