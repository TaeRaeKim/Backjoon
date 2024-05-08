#include <bits/stdc++.h>
using namespace std;

int e, s, t;
int main() {
	cin >> e >> s >> t;

	int i=1, j=1, k=1;
	int year = 1;
	while (true) {
		if (i == e && j == s && k == t) break;
		i++; j++; k++; year++;
		if (i > 15) i = 1;
		if (j > 28) j = 1;
		if (k > 19) k = 1;
	}
	cout << year; 
	return 0;
}