#include <bits/stdc++.h>
using namespace std;


int N, M;
int result[9];

void permutation(int n, int d) {
	result[d] = n;
	if(d==M){
		for (int i = 1; i <= M; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		permutation(i, d + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> N >> M;

	permutation(0, 0);
	return 0;
}