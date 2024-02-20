#include <iostream>
#include <vector>
using namespace std;

#define mod 10007
int N;
int D[1001][10] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	
	for (int i = 0; i < 10; i++) {
		D[1][i] = 1;
	}

	for (int n = 2; n <= N; n++) {
		for (int i = 0; i < 10; i++) {
			for (int j = i; j >= 0; j--) {
				D[n][i] = D[n][i] + D[n-1][i - j] % mod;
			}
		}
	
	}
	int answer = 0;
	for (int i = 0; i < 10; i++) {
		answer += D[N][i];
	}
	
	cout << answer % mod << '\n';

	return 0;
}