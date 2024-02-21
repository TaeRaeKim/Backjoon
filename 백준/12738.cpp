#include <bits/stdc++.h>
using namespace std;

vector<int> answer;
int N, a;

void input(int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		input(a);
	}
	cout << answer.size();

	return 0;
}

void input(int i) {
	if (answer.empty()) answer.push_back(i);
	else if (answer.back() < i) answer.push_back(i);
	else *lower_bound(answer.begin(), answer.end(), i) = i;
}