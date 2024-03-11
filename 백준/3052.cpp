#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	set<int> s;
	for (int i = 0, t; i < 10; i++) {
		cin >> t;
		s.insert(t % 42);
	}

	cout << s.size();

	return 0;
}