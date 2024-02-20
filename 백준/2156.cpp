//시작 시간 6시40분

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int N, amount;
	cin >> N;
	vector<int> dp(N+1);
	vector<int> arr(N + 1);

	
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	dp[3] = max(dp[3],dp[2]);

	for (int n = 4; n <= N; n++) {
		dp[n] = max(dp[n - 3] + arr[n - 1] + arr[n], dp[n - 2] + arr[n]);
		dp[n] = max(dp[n], dp[n - 1]);
	}

	cout << dp[N] << endl;

	return 0; 
}
