#include <bits/stdc++.h>
using namespace std;

vector<int> answer;
int N, x;
void input(int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		input(x);
	}
	cout << answer.size();
	return 0;
}

void input(int x) {
	if (answer.empty()) answer.push_back(x);
	else if (answer.back() < x) answer.push_back(x);
	else *lower_bound(answer.begin(), answer.end(), x) = x;
}