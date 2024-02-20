#include <iostream>
using namespace std;

int N;
bool arr[128][128];

void solve(int, int, int);
int blue, white;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, N);
	cout << white << '\n';
	cout << blue << '\n';

	return 0;
}

void solve(int I, int J, int N) {
	if (N == 1) {
		if (arr[I][J] == 1) blue++;
		else white++;
		return;
	}

	bool cut = false;
	bool color = arr[I][J];
	for (int i = I; i < I + N && !cut; i++) {
		for (int j = J; j < J + N; j++) {
			if (color != arr[i][j]) {
				cut = true;
			}
		}
	}
	if (cut) {
		solve(I, J, N/2);
		solve(I+ N/2, J, N/2);
		solve(I, J+ N/ 2, N/2);
		solve(I+ N/2, J+ N/2, N/2);
	}
	else {
		if (arr[I][J] == 1) blue++;
		else white++;
	}
}