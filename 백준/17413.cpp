#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(stack<char>*);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	getline(cin,str);

	stack<char> s;

	bool tag = false;  // true 일때 정방향
	for (char c : str) {
		if (c == '<') {
			tag = true;
			print(&s);
			cout << c;
		}
		else if (c == '>') {
			tag = false;
			cout << c;
		}
		else if (c == ' ') {
			print(&s);
			cout << c;
		}
		else {
			if (tag) {
				cout << c;
			}
			else {
				s.push(c);
			}
		}
	}
	print(&s);

	return 0;
}

void print(stack<char> *s) {
	while (!s->empty()) {
		cout << s->top();
		s->pop();
	}
}