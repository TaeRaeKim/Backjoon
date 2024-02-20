#include <bits/stdc++.h>
using namespace std;

#define MAX 100002

vector<int> arr(MAX);
vector<int> ston(MAX);
vector<int> eton(MAX);

int N, M;
int Ans;
int s, e;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		ston[i] = ston[i - 1] + arr[i];
	}
	for (int i = N; i >= 1; i--) {
		eton[i] = eton[i + 1] + arr[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		cout << ston[N] - ston[s - 1] - eton[e + 1] << '\n';
	}
	return 0;
}