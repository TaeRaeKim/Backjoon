#include <iostream>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	int D[1001] = {0,};
	int arr[1001];
	int answer = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	
	for (int x = N; x >= 1; x--) {
		for (int i = x + 1; i <= N; i++) {
			if (arr[x] < arr[i]) D[x]=max(D[x], D[i]);
		}
		D[x]++;
		answer = max(answer, D[x]);
	}

	cout << answer << '\n';

	return 0;
}