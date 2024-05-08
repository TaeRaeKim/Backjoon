#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
	cin >> N;

	int p = 0;
	int ans = 0;
	while (N >= pow(10, p)) {
		if (N < pow(10, p + 1)) {
			ans += (p + 1) * (N- pow(10, p)+1);
		}
		else {
			ans += (p + 1) * (pow(10, p + 1) - pow(10, p));
		}
		p++;
	}
	cout << ans;
	return 0;
}