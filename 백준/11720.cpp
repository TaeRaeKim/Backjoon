#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string str;
	int sum = 0;

	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		sum += str[i] - '0';
	}
	cout << sum << '\n';

	return 0;
}