#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC = 0;
	cin >> TC;
	for (int T = 1; T <= TC; T++) {
		int answer = 0;
		int A, B;
		cin >> A >> B;
		answer = A + B;
		cout << "Case #" << T << ": " << answer << '\n';
	}

	return 0;
}