// 문제 시작시간 : 0555
// 풀이 완료시간 : 0622
// 스스로 풀었는가 : O

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Ans[1001][2];
vector<vector<int>> D(1002,vector<int>(2));
int arr[1002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
		for (int i = 0; i < n; i++) {
			D[n][0] = max(D[i][0], D[i][1]);
			if (arr[i] < arr[n]) D[n][1] = max(D[n][1], D[i][1] + 1);
			else D[n][1] = max(D[n][1], 1);
		}
		Ans[n][0] = max(D[n][0], D[n][1]);
	}

	for (int i = 0; i <= N+1; i++) {
		D[i].assign(2, 0);
	}

	for (int n = N; n >= 1; n--) {
		for (int i = n + 1; i <= N+1; i++) {
			D[n][0] = max(D[i][0], D[i][1]);
			if (arr[i] < arr[n]) D[n][1] = max(D[n][1], D[i][1] + 1);
			else D[n][1] = max(D[n][1], 1);
		}
		Ans[n][1] = max(D[n][0], D[n][1]);
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, Ans[i][0] + Ans[i][1] -1 );
	}

	cout << answer << endl;

	return 0;
}
