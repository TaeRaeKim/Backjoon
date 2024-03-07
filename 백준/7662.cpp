#include <bits/stdc++.h>
using namespace std;

multiset<int, greater<int>> s;
int TC, K, t;
char c;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> TC;
	for (int tc=0; tc < TC; tc++) {
		s.clear();
		cin >> K;
		for (int k = 0; k < K; k++) {
			cin >> c;
			cin >> t;
			if (c == 'I') {
				s.insert(t);
			}
			else if (c == 'D') {
				if (s.empty())continue;
				if (t == 1) s.erase(s.begin());
				else {
					s.erase(--s.end());
				}
			}
		}
		if (s.empty()) cout << "EMPTY" << '\n';
		else cout << *s.begin() << " " << *s.rbegin() << '\n';
	}
	return 0;
}