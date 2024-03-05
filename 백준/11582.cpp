#include <bits/stdc++.h>
using namespace std;

int N; int K;
vector<int> arr(1024 * 1024);

void msort(int i, int k) {
	sort(arr.begin() + i, arr.begin() + i +k);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> K;
	int start, end;
	start = log2(N);
	end = log2(K);

	for (int i = start, j = 1; i > end; i--, j++) {
		int k = pow(2, j);
		for (int l = 0; l < N; l+=k) {
			msort(l, k);			
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}