#include <iostream>
#include <stack>
#include <string>
using namespace std;

void printStack(stack<char> *s);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int TC;
	cin >> TC;
	cin.ignore();

	for (int T = 0; T < TC; T++) {
		stack<char> s;
		string str;

		getline(cin, str);
		
		for (char c : str) {
			if (c == ' ') {
				printStack(&s);
			}
			else {
				s.push(c);
			}
		}
		printStack(&s);

		cout << '\n';
	}

	return 0;
}

void printStack(stack<char> *s) {
	while (!s->empty()) {
		cout << s->top();
		s->pop();
	}
	cout << ' ';
}