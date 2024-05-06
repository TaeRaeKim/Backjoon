#include <bits/stdc++.h>
using namespace std;
int main() {
	long long x, y;
	int temp, ans = 0;
	cin >> x >> y;
	temp = sqrt(2 * x + 2 * y);
	if ((long long)temp * temp + temp == (2 * x + 2 * y)) {
		for (int i = temp; i > 0 && x > 0; i--) {
			if (i <= x) {
				x -= i;
				ans++;
			}
		}
	}
	else ans = -1;
	cout << (ans >= 0 ? ans : -1);
	return 0;
}