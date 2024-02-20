// ���� ���۽ð� : 0720 
// Ǯ�� �Ϸ�ð� : �ǹ� ����. ���� ���� ���� ǰ ���� �ʿ�
// ������ Ǯ���°� : X 
// ���� Ƚ�� : 0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr(100001);
vector<int> D(100001); // n���� ������ ������
vector<int> Dr(100001); // n���� �����ϴ� ������
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
