#include <iostream>
#include <cmath>
using namespace std;

string solve(int, int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int A, B, C;
	while (cin >> A >> B >> C) {
		if (A == 0 && B == 0 && C == 0) break;
		cout << solve(A, B, C) << '\n';
	}
	return 0;
}

string solve(int a, int b, int c) {
	string right = "right";
	string wrong = "wrong";

	int length = max({ a,b,c });

	if ((length == a) && (pow(a, 2) == (pow(b, 2) + pow(c, 2)))) return right;
	else if ((length == b) && (pow(b, 2) == (pow(a, 2) + pow(c, 2)))) return right;
	else if ((length == c) && (pow(c, 2) == (pow(a, 2) + pow(b, 2)))) return right;
	return wrong;
}