#include <bits/stdc++.h>
using namespace std;

int Tc, t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> Tc;
	for (int tc = 0; tc < Tc; tc++) {
		int N, M, x, y;
		int ans = 1;
		bool check = true;

		cin >> N >> M >> x >> y;
		x--; y--;

		int i = 0, j = 0;
		while(i < x){
			i++, j++, ans++;
			j %= M;
		}
		bool find = false;
		for (int k = 0; k < M; k++) {
			if (i == x && j == y) {
				find = true;
				break;
			}
			j += N;
			j %= M;
			ans += N;
		}
		cout << (find ? ans : -1) << '\n';
	}

	return 0;
}