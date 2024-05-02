#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100000], ans = 1;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int lectureLength;
	int start, end;
	start = 0, end = N - 1;


	for (int l = 1; l <= 10000; l++) {
		lectureLength = l;
		int lectureCount = 0;
		int start, end;
		start = 0, end = N - 1;
		while (start <= end) {
			if (arr[start] >= lectureLength) {
				lectureLength = l;
				lectureCount++;
			}
			else {
				lectureLength -= arr[start];
				start++;
			}
			if (lectureCount > M) break;
		}
		if (lectureCount == M) {
			ans = l;
		}
		else if(lectureCount < M){
			break;
		}
	}
	cout << ans;

	return 0;
}