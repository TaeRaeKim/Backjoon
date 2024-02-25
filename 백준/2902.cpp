#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> vec;
	int prev = 0, i = 0;
	while (string::npos != (i = s.find('-', prev))) {
		vec.push_back(s.substr(prev, i - prev));
		prev = i + 1;
	}
	vec.push_back(s.substr(prev, i - prev));

	for (string ch : vec) {
		cout << ch[0];
	}
	return 0;
}