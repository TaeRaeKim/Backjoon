#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int P[1001];
	int D[1001];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	D[0] = 0;
	D[1] = P[1];

	int mx = 0;
	for (int i = 2; i <= N; i++) {
		mx = 0;
		for (int j = 1; j <= i; j++) {
			mx = max(mx, D[i - j] + P[j]);
		}
		D[i] = mx;
	}

	cout << D[N] << '\n';

	return 0;
}