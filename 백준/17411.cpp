//못푼문제입니다.

#include <bits/stdc++.h>
using namespace std;

#define LIS_MAX 1000*1000+1
#define LIS_MOD (1000*1000*1000+7)

vector<int> dp(LIS_MAX);
vector<int> forLength;
vector<int> forCount(LIS_MAX);

int N, max_count, x;
long long int answer = 0;
int inputForLength(int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		dp[i] = inputForLength(x);
		forCount[dp[i]]++;
		if (max_count < dp[i]) max_count = dp[i];
	}
	answer = forCount[max_count] % LIS_MOD;

	cout << forLength.size() << " " << answer;


	return 0;
}

int inputForLength(int x) {
	if (forLength.empty()) forLength.push_back(x);
	else if (forLength.back() < x) forLength.push_back(x);
	else {
		int t = lower_bound(forLength.begin(), forLength.end(), x) - forLength.begin();
		forLength[t] = x;
		return (t + 1);
	}
	return forLength.size();
}