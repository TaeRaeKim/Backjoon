#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000000
int D[1000001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC, N;
	cin >> TC;
	D[0] = 1;
	D[1] = 1;
	D[2] = 2;

	for (int i = 3; i <= MAX; i++) {
		D[i] = (((D[i - 3] + D[i - 2]) % 1000000009) + D[i - 1]) % 1000000009;
	}

	for (int tc = 0; tc < TC; tc++) {
		cin >> N;
		cout << D[N] << '\n';
	}

	return 0;
}