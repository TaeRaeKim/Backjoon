#include <bits/stdc++.h>
using namespace std;
#define HIGH 64 * 1000 * 1000 + 1

int N, M, B;
int arr[500][500];
int ans[2], minHeight=256, maxHeight, blockCount, timeArr[257];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> blockCount;
	ans[0] = HIGH;
	ans[1] = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			minHeight = min(minHeight, arr[i][j]);
			blockCount += arr[i][j];
		}
	}
	maxHeight = min(256, blockCount / (N * M));
	for (int k = minHeight; k <= maxHeight; k++) {
		for (int i = 0; (i < N) && (timeArr[k] <= ans[0]); i++) {
			for (int j = 0; (j < M) && (timeArr[k] <= ans[0]); j++) {
				if (k > arr[i][j]) timeArr[k] += k - arr[i][j];
				else if (k < arr[i][j]) timeArr[k] += (arr[i][j]-k) * 2;
			}
		}
		if (ans[0] >= timeArr[k]) {
			ans[0] = timeArr[k];
			ans[1] = k;
		}
	}
	cout << ans[0] << " " << ans[1];

	return 0;
}