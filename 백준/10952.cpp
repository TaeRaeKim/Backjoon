#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	while (cin >> A >> B) {
		if (A == B && B == 0)
			break;
		cout << (A + B) << '\n';
	}
	return 0;
}