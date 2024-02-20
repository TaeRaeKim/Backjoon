// 문제 시작시간 : 0510
// 풀이 완료시간 : 0537
// 스스로 풀었는가 : O

#include <iostream>
#include <algorithm>
using namespace std;

int D[1001][2];
int arr[1001];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int n = 1; n <= N; n++) {
		D[n][1] = 1;
		for (int i = 0; i < n; i++) {
			D[n][0] = max({ D[n][0], D[i][0], D[i][1] });
			if (arr[i] > arr[n]) D[n][1] = max( D[n][1], D[i][1]+1);
		}
	}
	cout << max(D[N][0], D[N][1]) << '\n';
	return 0;
}
