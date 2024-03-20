#include <bits/stdc++.h>
using namespace std;

string str, ans = "{";
string btof(string value) {
	string t;
	for (int i = value.length() - 1; i >= 0; i--)t += value[i];
	return t;
}
string min(string, string, string);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> str;
	int N = str.length();
	for (int i = 1; i <= N - 2; i++) {
		for (int j = i + 1; j <= N - 1; j++) {
			ans = min(ans, btof(str.substr(0, i)) + btof(str.substr(i, j - i)) + btof(str.substr(j, N - j + 1)));
		}
	}
	cout << ans;
	return 0;
}