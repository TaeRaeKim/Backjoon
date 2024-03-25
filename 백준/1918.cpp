#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	stack<char> s;
	cin >> str;

	char t;
	for (char c : str) {
		if ((c >= 'A' && c <= 'Z' )|| c=='(') {
			s.push(c);
		}
		if (c == '*' || c == '/') {
			while (!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-') {
				t = s.top(); s.pop();
				cout << t;
			}
			s.push(c);
		}
		if (c == '+' || c == '-') {
			while (!s.empty() && s.top() != '(') {
				t = s.top(); s.pop();
				cout << t;
			}
			s.push(c);
		}
		if (c == ')') {
			while (!s.empty() && s.top() != '(') {
				t = s.top(); s.pop();
				cout << t;
			}
			s.pop();
		}
	}
	while (!s.empty()) {
		t = s.top(); s.pop();
		cout << t;
	}

	return 0;
}
