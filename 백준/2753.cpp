#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	int answer = 0;
	if (N % 400 == 0) answer = 1;
	else if (N % 4 == 0 && N % 100 != 0) answer = 1;
	
	cout << answer << '\n';

	return 0;
}