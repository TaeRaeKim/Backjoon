// 문제 시작시간 : 0720 
// 풀이 완료시간 : 의미 없음. 백준 강의 보고 품 복습 필요
// 스스로 풀었는가 : X 
// 복습 횟수 : 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr(100001);
vector<int> D(100001); // n으로 끝나는 연속합
vector<int> Dr(100001); // n으로 시작하는 연속합
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> arr[1];
	D[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		cin >> arr[i];
		D[i] = max(arr[i], D[i - 1] +arr[i]);
	}
	Dr[N] = arr[N];
	for (int i = N-1; i >= 1; i--) {
		Dr[i] = max(arr[i], Dr[i + 1] + arr[i]);
	}
	int ans = D[1];
	for (int i = 2; i <= N; i++) if (ans < D[i]) ans = D[i];
	for (int i = 2; i <= N - 1; i++) if (ans < D[i - 1] + Dr[i + 1]) ans = D[i - 1] + Dr[i + 1];

	cout << ans << '\n';
}
