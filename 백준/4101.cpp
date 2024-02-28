#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	while (A != 0 || B != 0) {
		if (A <= B) cout << "No\n";
		else cout << "Yes\n";
		cin >> A >> B;
	}
	return 0;
}