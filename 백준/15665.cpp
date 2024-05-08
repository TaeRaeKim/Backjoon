#include <bits/stdc++.h>
using namespace std;

set<int> s;
int N, M;
int result[8];
void permutation(int number, int d) {
	result[d] = number;
	if (d == M) {
		for (int i = 1; i <= M; i++) cout << result[i] << ' ';
		cout << '\n';
		return;
	}
	for (int t : s) {
		permutation(t, d + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		s.insert(t);
	}
	
	permutation(0, 0);

	return 0;
}