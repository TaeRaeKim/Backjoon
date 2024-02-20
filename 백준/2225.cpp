#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> D(201, vector<int>(201, -1));

int DP(int n, int k) {
	if (D[n][k] >= 0) {
		return D[n][k];
	}
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		D[i][k - 1] = DP(i, k - 1);
		sum = (sum + D[i][k - 1]) % 1000000000;
	}
	D[n][k] = sum;
	return D[n][k];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		D[i][0] = 0;
		D[i][1] = 1;
	}

	cout << DP(N, K) << endl;
	return 0;
}