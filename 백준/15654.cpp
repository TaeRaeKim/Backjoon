//#include <bits/stdc++.h>
//using namespace std;
//
//int N, K;
//vector<int> arr(9);
//int ans[9];
//bool use[9];
//void solve(int d) {
//	for (int i = 1; i <= N; i++) {
//
//		if (use[i]) {
//			continue;
//		}
//		use[i] = true;
//		ans[d] = arr[i];
//
//		if (d == K) {
//			for (int m = 1; m <= K; m++) cout << ans[m] << " ";
//			cout << '\n';
//		}
//		else solve(d + 1);
//		use[i] = false;
//	}
//}
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr); cout.tie(nullptr);
//
//	cin >> N >> K;
//	for (int i = 1; i <= N; i++) {
//		cin >> arr[i];
//	}
//	sort(arr.begin() + 1, arr.begin() + N + 1);
//
//	solve(1);
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int N, M;
int result[9];
int arr[9];
bool check[9];
void permutation(int n, int d) {
	result[d] = arr[n];
	if (d == M) {
		for (int i = 1; i <= M; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			check[i] = true;
			permutation(i, d + 1);
			check[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	sort(arr+1, arr + N+1);
	permutation(0, 0);

}