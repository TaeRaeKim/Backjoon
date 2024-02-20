#include <iostream>
using namespace std;

unsigned int D[100001][4];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC, N;
	cin >> TC;
	D[1][0] = 1;
	D[1][1] = 1;
	D[1][2] = 0;
	D[1][3] = 0;

	D[2][0] = 1;
	D[2][1] = 0;
	D[2][2] = 1;
	D[2][3] = 0;

	D[3][0] = 3;
	D[3][1] = 1;
	D[3][2] = 1;
	D[3][3] = 1;
	for (int n = 4; n <= 100000; n++) {
		D[n][0] =
			((D[n - 1][2] + D[n - 1][3]) % 1000000009 +
				(D[n - 2][1] + D[n - 2][3]) % 1000000009 +
				(D[n - 3][1] + D[n - 3][2]) % 1000000009) % 1000000009;

		D[n][1] = (D[n - 1][2] + D[n - 1][3]) % 1000000009;
		D[n][2] = (D[n - 2][1] + D[n - 2][3]) % 1000000009;
		D[n][3] = (D[n - 3][1] + D[n - 3][2]) % 1000000009;
	}

	for (int tc = 0; tc < TC; tc++) {
		cin >> N;
		cout << D[N][0] << '\n';
	}


	return 0;
}