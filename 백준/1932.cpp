// ���� ���۽ð� : 0400
// Ǯ�� �Ϸ�ð� : 0413
// ������ Ǯ���°� : O

#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500];
int Darr[500][500];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	Darr[0][0] = arr[0][0];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++){
			if (j == 0) Darr[i][j] =Darr[i - 1][j] + arr[i][j];
			else if(j < N-1) Darr[i][j] = max(Darr[i-1][j-1], Darr[i-1][j]) + arr[i][j];
			else Darr[i][j] = Darr[i - 1][j-1] + arr[i][j];
		}
	}
	int answer = 0;
	for(int j=0; j<N; j++)
		answer = max(answer, Darr[N -1][j]);

	cout << answer << '\n';

	return 0;
}
