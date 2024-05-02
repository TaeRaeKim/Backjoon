#include <bits/stdc++.h>
using namespace std;

int N;
int arr[50];
int M;
long long int combination(int n, int r) {
	long long int result = 1;
	for (int i = n; i >= n - r + 1; i--) {
		result *= i;
	}
	for (int i = r; i > 1; i--) {
		result /= i;
	}
	return result;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> M;

	sort(arr, arr + N);

	int min = *(lower_bound(arr, arr + N, M) - 1);
	bool check = *lower_bound(arr, arr + N, M) == M;
	int max = *upper_bound(arr, arr + N, M);
	int count = 0;
	for (int i = min + 1; i <= max - 2; i++) {
		for (int j = i + 1; j <= max - 1; j++) {
			if (i <= M && j >= M)count++;
		}
	}
	if (check) cout << 0;
	else cout << count;

	return 0;
}