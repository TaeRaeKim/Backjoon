#include <bits/stdc++.h>
using namespace std;

int N, a, b, c;
int D[2][3], minList[3], maxList[3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin >> a >> b >> c;
	maxList[0] = minList[0] = D[0][0] = D[1][0] = a;
	maxList[1] = minList[1] = D[0][1] = D[1][1] = b;
	maxList[2] = minList[2] = D[0][2] = D[1][2] = c;
	
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;

		minList[0] = min(D[0][0], D[0][1]) + a;
		minList[1] = min({ D[0][0], D[0][1], D[0][2] }) + b;
		minList[2] = min(D[0][1], D[0][2]) + c;

		maxList[0] = max(D[1][0], D[1][1]) + a;
		maxList[1] = max({ D[1][0], D[1][1], D[1][2] }) + b;
		maxList[2] = max(D[1][1], D[1][2]) + c;
		D[0][0] = minList[0];
		D[0][1] = minList[1];
		D[0][2] = minList[2];
		D[1][0] = maxList[0];
		D[1][1] = maxList[1];
		D[1][2] = maxList[2];
	}

	cout << max({ maxList[0],  maxList[1],  maxList[2] }) << " " << min({ minList[0], minList[1], minList[2] });
	return 0;
}