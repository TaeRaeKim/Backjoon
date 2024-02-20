#include <iostream>
#include <string>
#include <set>
using namespace std;

bool compare(string a, string b) {
	if (a.length() < b.length()) return true;
	else if (a.length() > b.length()) return false;
	else return a.compare(b) < 0 ? true : false;
};

int N;
set<string, decltype(&compare)> s(compare);
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	for (string value : s) {
		cout << value << '\n';
	}
	return 0;
}
