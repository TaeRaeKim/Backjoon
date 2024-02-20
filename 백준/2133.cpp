// 문제 시작시간 : 0320
// 풀이 완료시간 : 0400
// 스스로 풀었는가 : O

#include <iostream>
using namespace std;

int D[31][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	D[1][1] = 1;
	D[1][2] = 1;
	D[1][3] = 1;
	int temp = 0;
	for (int n = 2; n <= (N/2); n++) {
		temp = D[n - 1][1] + D[n - 1][2] + D[n - 1][3];
		D[n][1] = temp + D[n - 1][1];
		D[n][2] = temp;
		D[n][3] = temp + D[n - 1][3];
	}
	temp = D[N / 2][1] + D[N / 2][2] + D[N / 2][3];
	if (N % 2 == 0) cout <<temp  << '\n';
	else cout << 0 << '\n';


	return 0;
}