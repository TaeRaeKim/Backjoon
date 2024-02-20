#include <iostream>
#include <string>
#include <stack>
using namespace std;

char answer[600000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int M = 0;
	char command;
	stack<char> left;
	stack<char> right;

	string str;
	cin >> str;

	for (char c : str) {
		left.push(c);
	}

	cin >> M;
	for (int m = 0; m < M; m++) {
		cin >> command;

		if (command == 'L') {
			if (left.empty()) continue;
			right.push(left.top());
			left.pop();	
		}
		if (command == 'D') {
			if (right.empty()) continue;
			left.push(right.top());
			right.pop();
		}
		if (command == 'B') {
			if (left.empty())continue;
			left.pop();
		}
		if (command == 'P') {
			char c;
			cin >> c;
			left.push(c);
		}
	}

	//while (!left.empty()) {
	//	right.push(left.top());
	//	left.pop();			
	//}

	//while (!right.empty()) {
	//	cout << right.top();
	//	right.pop();
	//}
	//cout << '\n';

	int index = left.size();
	int i = 0;

	for (i = left.size() - 1; !left.empty(); left.pop(), i--) {
		answer[i] = left.top();
	}
	
	for (i = index; !right.empty(); right.pop(), i++) {
		answer[i] = right.top();
	}

	cout << answer << '\n';

	return 0;
}