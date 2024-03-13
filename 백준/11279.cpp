#include <bits/stdc++.h>
using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	priority_queue<int> s;
	
	cin >> N;
	for (int i = 0, t;  i < N; i++) {
		cin >> t;
		if (t == 0) {
			if (s.empty()) cout << '0' << '\n';
			else {
				cout << s.top() << '\n'; s.pop();
			}
		}
		s.push(t);
	}

	return 0;
}