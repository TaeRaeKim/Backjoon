#include <iostream>
#include <stack>
using namespace std;

int arr[500001];
int answer[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> s;

	int N, v;
	cin >> N;

	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	int t;

	s.push(N);
	for (int n = N - 1; n > 0; n--) {
		t = s.top();
		while (arr[t] < arr[n]) {
			answer[t] = n;
			s.pop();
			if (s.empty()) t = n;
			else {
				t = s.top();
			}
		}
		s.push(n);
	}
	while (!s.empty()) {
		t = s.top();
		answer[t] = 0;
		s.pop();
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << " ";
	}
	cout << endl;

	return 0;
}