#include <bits/stdc++.h>
using namespace std;

int N, C, arr[200000];
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int start, mid, end;
	start = 1;
	end = arr[N - 1] - arr[0];

	while (start <= end) {
		mid = (start + end) / 2;
		int cnt = 1;
		int prev = 0;
		for (int i = 1; i < N; i++) {
			if (mid <= arr[i] - arr[prev]) {
				cnt++;
				prev = i;
			}
		}

		if (cnt >= C) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans;

	return 0;
}