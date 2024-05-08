#include <bits/stdc++.h>
using namespace std;

bool check[9];
int result[9];
int N, M;

void permutation(int v, int d) {

	result[d] = v;
	if (d == M) {
		for (int i = 1; i <= M; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			check[i] = true;
			permutation(i, d + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> N >> M;

	permutation(0, 0);

	return 0;
}