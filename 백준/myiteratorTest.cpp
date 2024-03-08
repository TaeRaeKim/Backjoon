#include <bits/stdc++.h>
using namespace std;

set<int> s;
int main() {
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);

	for (int i : s) {
		cout << i << " ";
	}

	cout << endl;

	for (auto i = s.rbegin(); i != s.rend(); i++) {
		cout << *i << " ";
	}

	cout << endl;

	cout << *--(s.rbegin().base()) << endl;
	cout << *--s.rbegin().base() << endl;

	return 0;
}