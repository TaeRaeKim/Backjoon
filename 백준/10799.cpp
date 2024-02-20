#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	getline(cin, str);

	int mac = 0;
	int answer = 0;
	char before;
	for (char c : str) {
		if (c == '(') mac++;
		else {
			if (before == '(')	answer += mac-- - 1;
			else {
				mac--;
				answer++;
			}
		}
		before = c;
	}

	cout << answer << '\n';

	return 0;
}