#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC = 0;
	cin >> TC;
	for (int T = 0; T < TC; T++) {
		int A, B, answer;
		cin >> A >> B;
		answer = A + B;
		cout << answer << '\n';
	}	
	return 0;
}

