#include <bits/stdc++.h>
using namespace std;
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
	
	while (!(before.first == 1 && before.second == 0)) {
		swap(before.first, before.second);
		before.second = (before.first + before.second) % mod;
		c++;
	}
	cout << c;
	
	return 0;
}