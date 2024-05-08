#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[9];
int result[9];

void permutation(int n, int d) {
	result[d] = arr[n];
	if (d == M) {
		for (int i = 1; i <= M; i++) cout << result[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = n; i <= N; i++) {
		permutation(i, d + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	sort(arr + 1, arr + N + 1);
	permutation(1, 0);

	return 0;
}