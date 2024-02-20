#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;

	cin >> N;
	
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;

	int mini;
	for (int i = 4; i <= N; i++) {
		mini = 1000000;
		if (i % 3 == 0) mini = min(mini, DP[i / 3]);
		if (i % 2 == 0) mini = min(mini, DP[i / 2]);
		mini = min(mini, DP[i - 1]);
		DP[i] = mini + 1;
	}

	cout << DP[N] << '\n';
	return 0;
}