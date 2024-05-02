#include <bits/stdc++.h>
using namespace std;

int TC, a, b;
int main() {
	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		int arr[15][15] = { 0, };
		cin >> a >> b;
		for (int j = 1; j <= b; j++) {
			arr[0][j] = j;
		}
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				for (int k = 1; k <= j; k++) {
					arr[i][j] += arr[i - 1][k];
				}
			}
		}
		cout << arr[a][b] << '\n';
	}
	return 0;
}