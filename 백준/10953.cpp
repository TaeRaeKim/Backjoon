#include <iostream>
using namespace std;

int main() {
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	int TC = 0;
	cin >> TC;
	for (int T = 0; T < TC; T++) {
		int A, B;
		char c;
		cin >> A >> c >> B;
		cout << A + B <<'\n';
	}
	return 0;
}