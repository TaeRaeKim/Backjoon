#include <bits/stdc++.h>
using namespace std;

int Tc, x, y;

int main() {
	cin >> Tc;
	for (int tc = 0; tc < Tc; tc++) {
		cin >> x >> y;
		
		int distance = y - x;
		int root = (int)sqrt(distance);

		int remain = distance - root * root;
		int ans = root * 2 - 1;

		if (remain == 0) {
			cout << ans << '\n';
		}
		else {
			ans += ceil((float)remain / root);
			cout << ans << '\n';
		}
	}
	return 0;
}