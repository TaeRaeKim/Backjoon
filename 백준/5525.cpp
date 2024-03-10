#include <bits/stdc++.h>
using namespace std;

int N, M;
string s;
int ans = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;
	cin >> s;

	string ioi = "IOI";

	int prev=0;
	while (string::npos != (prev = s.find(ioi, prev))) {
		prev = prev + ioi.length();
		int cnt=1;
		while ((prev+1) < s.length() && s[prev] == 'O' && s[prev + 1] == 'I') {
			cnt++;
			prev +=2;
		}
		if (cnt >= N) {
			ans = ans + cnt - N + 1;;
		}
	}
	cout << ans;
	return 0;
}
