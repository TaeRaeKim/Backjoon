#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	int nowPrice = arr[0];
	int ans = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] >= nowPrice * 2) {
			nowPrice = arr[i];
			ans++;
		}
	}
	cout << ans;

	return 0;
}