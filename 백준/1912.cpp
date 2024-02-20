#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> D(100001);
int arr[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	D.assign(N+1, -1001);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		D[i] = max(arr[i], D[i - 1] + arr[i]);
	}
	int max_num = -1001;
	for (int i = 1; i <= N; i++) {
		max_num = max(max_num, D[i]);
	}

	cout << max_num << '\n';

	return 0;
}