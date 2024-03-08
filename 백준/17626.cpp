#include <iostream>
using namespace std;

int N;
int D[50001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;	
	for (int i = 1; i <= N; i++) D[i] = 4;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j <= i; j++) {
			D[i] = min(D[i], D[i - j * j]+1);
		}
	}
	cout << D[N];
	return 0;
}