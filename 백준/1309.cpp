#include <iostream>
#include <vector>
using namespace std;

#define mod 9901
int N;
int D[3][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	D[0][1] = 1;
	D[1][1] = 1;
	D[2][1] = 1;

	for (int i = 2; i <= N; i++) {
		D[0][i] = (D[0][i - 1] + D[1][i - 1] + D[2][i - 1]) % mod;
		D[1][i] = (D[0][i - 1] + D[2][i - 1]) % mod;
		D[2][i] = (D[0][i - 1] + D[1][i - 1]) % mod;
	}

	cout << (D[0][N] + D[1][N] + D[2][N]) % mod << '\n';

	return 0;
}