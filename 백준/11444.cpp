#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define mod 1000000007

int N;
pair<int, int> before;
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	before.first = 0;
	before.second = 1;
	int c = 2;
	set<pii> s;
	while (c++ < N) {
		swap(before.first, before.second);
		before.second = (before.first + before.second) % mod;
		if (s.find(make_pair(before.first, before.second)) != s.end()) {
			cout << "checkmate!!" << endl;
			break;

		}
		s.insert(make_pair(before.first, before.second));
	}
	cout << before.first + before.second << " ";
	
	return 0;
}