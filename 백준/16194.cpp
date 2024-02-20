#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int D[1001];
	int P[1001];
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}

	D[1] = P[1];

	int mn;
	for (int n = 2; n <= N; n++) {
		mn = 10000;
		for (int i = 1; i < n; i++) {
			mn = min(mn, D[n - i] + D[i]);
		}
		mn = min(mn, P[n]);
		D[n] = mn;
	}

	cout << D[N] << '\n';

	return 0;
}