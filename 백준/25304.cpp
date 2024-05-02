#include <bits/stdc++.h>
using namespace std;

int value, N, v, c;
int main() {
	cin >> value;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v >> c;
		value -= v * c;
	}
	if (value == 0) cout << "Yes";
	else cout << "No";
	return 0;
}