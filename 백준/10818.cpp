#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int min_num=1000000, max_num = -1000000;
	int N;
	int k;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> k;
		max_num = max(max_num, k);
		min_num = min(min_num, k);
	}
	cout << min_num << " " << max_num << '\n';

	return 0;
}