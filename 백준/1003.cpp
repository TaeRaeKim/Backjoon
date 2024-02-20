// ���� ���۽ð� : 0123
// Ǯ�� �Ϸ�ð� : 0133
// ������ Ǯ���°� : O

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int TC, N;
	cin >> TC;

	int D[41][41];
	D[0][0] = 1,D[0][1] = 0;
	D[1][0] = 0,D[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		D[i][0] = D[i - 1][0] + D[i - 2][0];
		D[i][1] = D[i - 1][1] + D[i - 2][1];
	}
	for (int tc = 0; tc < TC; tc++) {
		cin >> N;
		cout << D[N][0] << " " << D[N][1] << '\n';
	}
	return 0;
}