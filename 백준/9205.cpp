#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

int Tc, N ;
pos sg;
pos cs[100];
pos rock;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> Tc;
	for (int tc = 0; tc < Tc; tc++) {
		cin >> N;
		cin >> sg.first >> sg.second;
		for (int i = 0; i < N; i++) {
			cin >> cs[i].first >> cs[i].second;
		}
		cin >> rock.first >> rock.second;
	}
	return 0;
}