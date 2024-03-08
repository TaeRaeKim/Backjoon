#include <bits/stdc++.h>
using namespace std;

int N, M;
int a, b;
vector<list<int>> ve(2000);
bool check[2000];

bool solve(int i, int d) {
	if (ve[i].empty()) return false;
	else if (d == 0) return true;
	check[i] = true;
	bool result = 0;
	for (int j : ve[i]) {
		if (!check[j]) {
			if (solve(j, d - 1)) {
				result = true;
				break;
			}
		}		
	}
	check[i] = false;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		if (solve(i, 4)) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}