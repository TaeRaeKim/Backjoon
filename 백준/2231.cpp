#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int M = i;
		int K = i;
		while (K > 0) {
			M += (K % 10);
			K /= 10;
		}
		if (M == N) {
			cout << i;
			return 0;
		}
	}

	cout << 0;


	return 0;
}