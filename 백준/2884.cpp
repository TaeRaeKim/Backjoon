#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int H, M;
	cin >> H >> M;
	M += 15;
	if (M >= 60) {
		M %= 60;
		H++;
	}	
	cout << ((--H < 0) ? (24 + H) : H) << " " << M << '\n';

	return 0;
}