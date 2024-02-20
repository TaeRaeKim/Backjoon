#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	
	int sum = 1;
	for (int i = N; i > K; i--) {
		sum *= i;
	}
	for (int i = N - K; i > 1; i--) {
		sum /= i;
	}
	cout << sum << '\n';

	return 0;
}