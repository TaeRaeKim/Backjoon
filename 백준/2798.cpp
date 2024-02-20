#include <iostream>
using namespace std;

int N, M;
int card[100];
int ans=0,temp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	for (int i = 0; i <= N - 3; i++) {
		for (int j = i + 1; j <= N - 2; j++) {
			for (int k = N-1; k > j; k--) {
				temp = card[i] + card[j] + card[k];
				if (M - ans > M - temp && temp<=M) ans = temp;
			}
		}
	}
	cout << ans;

	return 0;
}
