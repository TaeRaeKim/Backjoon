#include <bits/stdc++.h>
using namespace std;

int N, M, h[2];
int arr[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> h[0] >> h[1];
		arr[h[0]] = i;
		arr[h[1]] = i;
	}
	for (int i = 1, j=i+1; i <= M * 2 && j<=10000; i++) {
		if (arr[i] == 0) {
			if (j <= i) j = i + 1;
			while (arr[j] == 0) j++;
			arr[i] = arr[j];
			arr[j++] = 0;
		}
	}
	N %= (M * 2);
	if (N == 0) N = M * 2;
	cout << arr[N];
	
	return 0;
}