#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int N, x, y;
	cin >> N >> y;	
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x < y) cout << x << " ";
	}
	return 0;
}