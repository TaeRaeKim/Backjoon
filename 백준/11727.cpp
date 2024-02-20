#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int D[1001];
	
	
	int N;
	cin >> N;
	
	D[0] = -1; D[1] = 1; D[2] = 3;
	for (int i = 3; i <= N; i++) {
		D[i] = (D[i - 1] + (D[i - 2] * 2)) % 10007;
	}
	
	cout << D[N] << '\n';

	return 0;
}