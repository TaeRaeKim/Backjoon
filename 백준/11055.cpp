// 문제 시작시간 : 0420;
// 풀이 완료시간 :  0501
// 스스로 풀었는가 : O

#include <iostream>
#include <algorithm>
using namespace std;

int D[1001][2];
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	int ln0 = 0, ln1 = 0; // 마지막 위치저장
	cin >> N;
	
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
		for (int i = 0; i <= n; i++) {
			if (arr[i] >= arr[n]) D[n][0] = max({ D[n][0], D[i][0], D[i][1]   });
			else D[n][1] = max(D[n][1], D[i][1] + arr[n]);
		}
	}
	int answer = 0;
	
	cout << max(D[N][0], D[N][1]) << '\n';

	return 0;
}
