#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int i;
	string s;
	bool ans;
	deque<char> dq;
	while (cin >> i) {
		if (i == 0) break;
		s = to_string(i);
		ans = true;
		dq.clear();
		for (int i = 0; i < s.length(); i++) {
			dq.push_back(s[i]);
		}
		while (!(dq.size() == 1 || dq.empty())) {
			if (dq.front() != dq.back()) {
				ans = false;
				break;
			}
			dq.pop_back();
			dq.pop_front();
		}
		if (ans) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}
