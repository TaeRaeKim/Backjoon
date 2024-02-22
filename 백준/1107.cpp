#include <bits/stdc++.h>
using namespace std;

bool nF[10];
int N, M;
int Ans;

int onlyUseNumber(int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;

	Ans = abs(N - 100);
	int t;
	for (int i = 0; i < M; i++) {
		cin >> t;
		nF[t] = true;
	}

	for (int i = 0; i <= 1000000; i++) {
		int length = onlyUseNumber(i);
		if (length > 0) {
			length += abs(i - N);
			if (length < Ans) Ans = length;
		}
	}
	cout << Ans;
	return 0;
}

int onlyUseNumber(int x) {
	if (x == 0) return (nF[0] ? false : true);

	int length = 0;
	while (x > 0) {
		if (nF[x % 10]) return 0;

		x = x / 10;
		length++;
	}

	return length;
}