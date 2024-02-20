#include <iostream>
using namespace std;

int D[1001];

int DP(int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	D[0] = -1;
	D[1] = 1;
	D[2] = 2;
	cout << DP(N) << '\n';	

	return 0;
}

int DP(int n) {
	if (D[n] != 0) return D[n];
	D[n] = (DP(n - 1) + DP(n - 2)) % 10007;
	return D[n];
}