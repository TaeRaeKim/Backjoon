#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int TC = 0;
	cin >> TC;

	for (int tc = 0; tc < TC; tc++) {
		int D[11];

		int N;
		cin >> N;

		D[1] = 1;
		D[2] = 2;
		D[3] = 4;

		for (int n = 4; n <= N; n++) {
			D[n] = D[n - 1] + D[n - 2]  + D[n - 3];
		}

		cout << D[N] << '\n';

	}
	return 0;
}