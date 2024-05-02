#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int N, before, now;
int cnt, mingcd;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	cin >> before;
	cin >> now;
	mingcd = now-before;
	cnt += now - before;
	before = now;
	for (int i = 2; i < N; i++) {
		cin >> now;
		mingcd = gcd(mingcd, now - before);
		cnt += now - before;
		before = now;
	}

	cnt -= mingcd * (N - 1);
	cnt /= mingcd;

	cout << cnt;
	return 0;
}