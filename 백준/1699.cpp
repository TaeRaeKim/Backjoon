#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int arr[100001];
int D[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		D[i] = i;
	}
	for (int i = 1; i <= (int)sqrt(N); i++) {
		D[(int)pow(i,2)] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int x = 1; x <= (int)sqrt(i); x++) {
			D[i] = min(D[i], D[i - (int)pow(x,2)] + 1);
		}
	}
	cout << D[N] << '\n';

	return 0;
}