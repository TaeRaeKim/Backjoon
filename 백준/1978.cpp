#include <iostream>
using namespace std;

int N, M;
int ans = 0, sosu;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		sosu = 0;
		cin >> M;
		for (int j = 1; j < M; j++) {
			if (M % j == 0)sosu++;
		}
		if (sosu == 1) ans++;
	}
	cout << ans << " ";
	return 0;
}
