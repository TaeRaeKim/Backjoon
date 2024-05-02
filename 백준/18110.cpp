#include <bits/stdc++.h>
using namespace std;

int N;
int score[31], t;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int ankleSlice, neckSlice;
	ankleSlice = neckSlice = round(0.15 * N);
	for (int i = 0; i < N; i++) {
		cin >> t;
		score[t]++;
	}
	N = N - ankleSlice - neckSlice;
	for (int i = 1, j = 30; i <= 30; i++, j--) {
		if (score[i] < ankleSlice) {
			ankleSlice -= score[i];
			score[i] = 0;
		}
		else {
			score[i] -= ankleSlice;
			ankleSlice = 0;
		}
		if (score[j] < neckSlice) {
			neckSlice -= score[j];
			score[j] = 0;
		}
		else {
			score[j] -= neckSlice;
			neckSlice = 0;
		}
	}
	int sum = 0;
	for (int i = 1; i <= 30; i++) {
		sum += score[i] * i;
	}
	cout << (N > 0 ? round(1.0 * sum / N) : 0);

	return 0;
}