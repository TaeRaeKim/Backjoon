#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	string t = "";
	int ans= 0, v;
	bool trigger = false;
	for (char c : str) {
		if (c == '+' || c == '-') {
			v = stoi(t); t = "";
			ans += (trigger ? -v : v);
			if (c == '-')trigger = true;
		}
		else {
			t += c;
		}
	}
	v = stoi(t); t = "";
	ans += (trigger ? -v : v);

	cout << ans;

	return 0;
}  