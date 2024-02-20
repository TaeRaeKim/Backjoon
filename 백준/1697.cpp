#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
vector<int> arr(100001);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> q;

	cin >> N;
	cin >> K;
	arr.assign(100001, 100000);

	arr[N] = 0;
	q.push(N);
	int t;
	while (!q.empty()) {
		t = q.front();
		q.pop();
		if ( t > 0 && arr[t - 1] > arr[t] + 1) {
			arr[t - 1] = arr[t] + 1;
			q.push(t - 1);
		}
		if ( t < 100000 && arr[t + 1] > arr[t] + 1) {
			arr[t + 1] = arr[t] + 1;
			q.push(t + 1);
		}
		if ( t*2 <= 100000 && arr[t * 2] > arr[t] + 1) {
			arr[t * 2] = arr[t] + 1;
			q.push(t * 2);
		}
	}

	cout << arr[K];
	return 0;
}