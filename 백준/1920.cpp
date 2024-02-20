#include <iostream>
#include <set>
using namespace std;

int N, M;
long int temp;
bool ans;
set<long int> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		s.insert(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		ans = (s.find(temp) != s.end()) ? true : false;
		cout << (int)ans << '\n';
	}

	return 0;
}
