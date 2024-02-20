#include <iostream>
using namespace std;

int D[1001];
int arr[1001];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int n = N; n >= 1; n--) {
		D[n] = 1;
		for (int i = n+1; i <= N; i++)
			if (arr[n] > arr[i] && D[n] < D[i] + 1) D[n] = D[i] + 1;
	}
	int ans = D[1];
	for (int i = 2; i <= N; i++) {
		if (ans < D[i]) ans = D[i];
	}
	cout << ans << '\n';

	return 0;
}
