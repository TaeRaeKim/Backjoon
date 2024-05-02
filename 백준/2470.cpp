#include <bits/stdc++.h>
using namespace std;
#define N_MAX 100000

int N;
vector<int> arr(N_MAX);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.begin() + N);

	int start, mid, end;
	start = 0;
	end = N - 1;
	int ans[3];
	ans[0] = abs(arr[start] + arr[end]), ans[1] = arr[start], ans[2] = arr[end];
	while (start < end) {
		mid = abs(arr[start] + arr[end]);
		if (mid < ans[0]) {
			ans[0] = mid;
			ans[1] = arr[start];
			ans[2] = arr[end];
			if(ans[0] == 0) break;
		}

		if ( 0 < arr[start] + arr[end]) {
			end--;
		}
		else {
			start++;
		}
	}
	cout << ans[1] << " " << ans[2];
	return 0;
}