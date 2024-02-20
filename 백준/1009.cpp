#include <iostream>
using namespace std;

int solve(int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	int a, b;
	for (int t = 0; t < T; t++) {
		cin >> a >> b;
		cout << solve(a % 10, b) << '\n';
	}

	return 0;
}

int solve(int a, int b) {
	if (a == 0) {
		return 10;
	}
	else if (a == 1) {
		return a;
	}
	else if (a == 2) {
		if (b % 4 == 1) return 2;
		if (b % 4 == 2) return 4;
		if (b % 4 == 3) return 8;
		if (b % 4 == 0) return 6;
	}
	else if (a == 3) {
		if (b % 4 == 1) return 3;
		if (b % 4 == 2) return 9;
		if (b % 4 == 3) return 7;
		if (b % 4 == 0) return 1;
	}
	else if (a == 4) {
		if (b % 2 == 1) return 4;
		if (b % 2 == 0) return 6;
	}
	else if (a == 5) {
		return 5;
	}
	else if (a == 6) {
		return 6;
	}
	else if (a == 7) {
		if (b % 4 == 1) return 7;
		if (b % 4 == 2) return 9;
		if (b % 4 == 3) return 3;
		if (b % 4 == 0) return 1;
	}
	else if (a == 8) {
		if (b % 4 == 1) return 8;
		if (b % 4 == 2) return 4;
		if (b % 4 == 3) return 2;
		if (b % 4 == 0) return 6;
	}
	else if (a == 9) {
		if (b % 2 == 1) return 9;
		if (b % 2 == 0) return 1;
	}
	else
		return -1;
}