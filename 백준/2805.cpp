#include <bits/stdc++.h>
using namespace std;
#define TREE_MAX 1000 * 1000
#define MAX_HEIGHT 1000 * 1000 * 1000

int N, M;
int arr[TREE_MAX];
int ans = 0;

bool isCorrect(int height) {
	long long int length = 0;
	for (int i = 0; i < N; i++) {
		length += (arr[i] > height ? arr[i] - height : 0);
		if (length >= M) {
			return true;
		}
	}
	return false;
}

int solve(int start, int end) {
	int mid, ret = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		if (isCorrect(mid)) {
			ret = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<int>());

	cout << solve(0, arr[0]);

	return 0;
}