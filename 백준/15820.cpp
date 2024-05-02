#include <bits/stdc++.h>
using namespace std;

int S[2];
int ans[2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S[0] >> S[1];

	for (int i = 0; i < S[0]; i++) {
		cin >> ans[0] >> ans[1];
		if (ans[0] != ans[1]) {
			cout << "Wrong Answer";
			return 0;
		}
	}
	for (int i = 0; i < S[1]; i++) {
		cin >> ans[0] >> ans[1];
		if (ans[0] != ans[1]) {
			cout << "Why Wrong!!!";
			return 0;
		}
	}
	cout << "Accepted";
	return 0;
}