#include <bits/stdc++.h>
using namespace std;

int N, ans;
int Arr[50];
int Brr[50];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> Arr[i];
	for (int i = 0; i < N; i++) cin >> Brr[i];
	sort(Arr, Arr + N);
	sort(Brr, Brr + N, greater<int>());

	for (int i = 0; i < N; i++) {
		ans += Arr[i] * Brr[i];
	}
	cout << ans;

	return 0;
}