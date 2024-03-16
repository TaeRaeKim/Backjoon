#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
vector<int> arr(MAX);
int sp, ep;
queue<int> q;

int ans[] = { 100000, 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> sp >> ep;

	arr.assign(MAX, 100000);

	arr[sp] = 0;
	q.push(sp);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t == ep) {
			ans[0] = arr[t];
			ans[1]++;
			continue;
		}

		if (t - 1 >= 0 && arr[t] + 1 <= arr[t - 1] && arr[t] < ans[0]) {
			arr[t - 1] = arr[t] + 1;
			q.push(t - 1);
		}
		if (t + 1 <= MAX - 1 && arr[t] + 1 <= arr[t + 1] && arr[t] < ans[0]) {
			arr[t + 1] = arr[t] + 1;
			q.push(t + 1);
		}
		if (t * 2 <= MAX - 1 && arr[t] + 1 <= arr[t * 2] && arr[t] < ans[0]) {
			arr[t * 2] = arr[t] + 1;
			q.push(t * 2);
		}
	}
	cout << ans[0] << '\n';
	cout << ans[1] << '\n';

	return 0;
}