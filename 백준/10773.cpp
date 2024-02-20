#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int K;
	double answer = 0;
	int n;
	stack<int> s;

	cin >> K;
	for (int k = 0; k < K; k++) {
		cin >> n;
		if (n == 0) {
			answer -= s.top();
			s.pop();
		}
		else {
			s.push(n);
			answer += n;
		}
	}
	cout << (int)answer << endl;

	return 0;
}