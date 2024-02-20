#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long int D[91][2] = {0};

	int N;
	cin >> N;
	D[1][0] = 0;
	D[1][1] = 1;
	D[2][0] = 1;
	D[2][1] = 0;

	for(int i=3; i<=N; i++){
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}

	cout << D[N][0] + D[N][1] << '\n';

	return 0;
}