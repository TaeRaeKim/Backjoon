#include <bits/stdc++.h>
using namespace std;

vector<int> arr(1000 * 1000 + 1);
vector<int> dp(1000 * 1000 + 1);
vector<int> answer;
stack<int> s;
int N;
int mi = 0;

int input(int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = input(arr[i]);
		if (dp[mi] < dp[i]) mi = i;
	}
	cout << answer.size() << '\n';

	s.push(arr[mi]);
	for (int i = mi - 1; i >= 0; i--) {
		if ((dp[i] + 1 == dp[mi]) && arr[i] < arr[mi]) {
			s.push(arr[i]);
			mi = i;
		}
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();

	}
	return 0;
}

int input(int x) {
	if (answer.empty()) answer.push_back(x);
	else if (answer.back() < x) answer.push_back(x);
	else {
		int t = lower_bound(answer.begin(), answer.end(), x) - answer.begin();
		answer[t] = x;
		return t;
	}
	return answer.size() - 1;
}