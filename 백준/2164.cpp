#include <iostream>
#include <deque>
using namespace std;

int N;
deque<int> dq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = N; i >= 1; i--) {
		dq.push_back(i);
	}
	while (dq.size() != 1 ){
		dq.pop_back();
		dq.push_front(dq.back());
		dq.pop_back();
	}
	cout << dq.back();

	return 0;
}
