#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(string);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC;
	cin >> TC;
	cin.ignore();

	for (int T = 0; T < TC; T++) {
		string str;
		stack<char> s;
		getline(cin, str);

		for (char c : str) {
			if (c == '(') {
				s.push('(');
			}
			else if (c == ')') {
				if (s.empty()) {
					s.push(')');
					break;
				}
				s.pop();
			}
		}
		if (s.empty())print("YES");
		else print("NO");
	}

	return 0;
}

void print(string str) {
	cout << str << '\n';
}