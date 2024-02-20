// 문제 시작시간 : 0240
// 풀이 완료시간 : 0355
// 스스로 풀었는가 : X

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001][3];
int D[100001][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int TC;
	int N;
	cin >> TC;
	int answer;
	for (int tc = 0; tc < TC; tc++) {
		answer = 0;
		cin >> N;
		for (int j = 1; j <= 2; j++) {
			for (int i = 1; i <= N; i++) {
				cin >> arr[i][j];
			}
		}

		D[1][0] = 0;
		D[1][1] = arr[1][1];
		D[1][2] = arr[1][2];
		for (int i = 2; i <= N; i++) {
			D[i][0] = max({ D[i - 1][0] ,D[i - 1][1] ,D[i - 1][2] });
			D[i][1] = max(D[i - 1][0], D[i - 1][2]) + arr[i][1];
			D[i][2] = max(D[i - 1][0], D[i - 1][1]) + arr[i][2];

		}
		answer = max({ D[N][0], D[N][1], D[N][2] });
		cout << answer << '\n';
	}
	return 0;
}
