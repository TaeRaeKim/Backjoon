#include <bits/stdc++.h>
using namespace std;

int TC, N, arr[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		int i = 0, j = N - 1, jc = 0;
		int ans[3] = { 0, };
		int temp = arr[i];
		while (arr[i] == arr[j] && i < (N - 1)) {
			i++;
		}
		if (i < N - 1) {
			ans[1] = (N - 1) - i;
		}
		while (temp == arr[j] && j > 0) {
			j--;
		}
		if (j > 0) {
			ans[2] = j - 0;
		}
		ans[0] = max(ans[1], ans[2]);
		cout << (ans[0] == 0 ? "BRAK" : to_string(ans[0])) << '\n';
	}
	return 0;
}