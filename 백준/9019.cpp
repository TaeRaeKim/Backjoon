#include <bits/stdc++.h>
using namespace std;

int D(int n) { return (n * 2 % 10000); }
int S(int n) { return (n != 0 ? n - 1 : 9999); }
int L(int n) { return (n * 10 % 10000) + (n  / 1000); }
int R(int n) { return (n % 10 * 1000) + (n / 10); }

int N, sp, ep;
vector<string> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sp >> ep;
		ans.assign(10000, "");
		queue<int> q;
		ans[sp] = "S";
		q.push(sp);
		while (!q.empty()) {
			int t = q.front(); q.pop();
			if (t == ep) break;
			if (ans[D(t)] == "") {
				ans[D(t)] = ans[t] + 'D';
				q.push(D(t));
			}
			if (ans[S(t)] == "") {
				ans[S(t)] = ans[t] + 'S';
				q.push(S(t));
			}
			if (ans[L(t)] == "") {
				ans[L(t)] = ans[t] + 'L';
				q.push(L(t));
			}
			if (ans[R(t)] == "") {
				ans[R(t)] = ans[t] + 'R';
				q.push(R(t));
			}
		}
		cout << ans[ep].substr(1, ans[ep].length()-1) << '\n';		
	}	
	return 0;
}