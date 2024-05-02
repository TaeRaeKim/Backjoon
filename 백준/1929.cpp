#include <bits/stdc++.h>
using namespace std;

int N, M;

bool isSosu(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	if (n == 1) return false;
	return true;
}
int main() {
	cin >> N >> M;
	for (int i = N; i <= M; i++) {
		if (isSosu(i)) cout << i << '\n';
	}

	return 0;
}