#include <bits/stdc++.h>
#define N_MAX 300+1
using namespace std;

int N;
int arr[N_MAX];
int D[2][N_MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	D[0][0] = 0;
	D[1][0] = 0;
	D[0][1] = 0;
	D[1][1] = arr[1];
	D[0][2] = arr[1];
	D[1][2] = arr[1] + arr[2];


	for (int i = 3; i <= N; i++) {
		D[0][i] = max({D[0][i - 3] + arr[i - 2] + arr[i - 1], D[1][i - 3] + arr[i - 1], D[0][i - 1]});
		D[1][i] = max(D[0][i - 2] + arr[i - 1] + arr[i], D[0][i - 1] + arr[i]);
	}
	cout << D[1][N];

	return 0;
}