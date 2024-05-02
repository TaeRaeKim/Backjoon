#include <bits/stdc++.h>
using namespace std;

int N;
long long int c = 1;
int ans;
int main() {
	cin >> N;

	while (N > 0) {
		N -= c;
		if(c > 1) c += 6;
		else  c = 6;
		ans++;
	}
	cout << ans;

	return 0;
}