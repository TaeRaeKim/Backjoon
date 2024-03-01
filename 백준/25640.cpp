#include <bits/stdc++.h>
using namespace std;

int distance(string,string);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int Tc, N;
	cin >> Tc;

	string s;
	int Ans;

	for (int tc = 0; tc < Tc; tc++) {
		map<string, int> m;
		Ans = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> s;
			m[s]++;
			if (m[s] >= 3) Ans = 0;
		}
		if (Ans != -1) {
			cout << Ans << '\n';
			continue;
		}
		vector<string> v;
		for (pair<string, int> p : m) {
			if(p.second>1)v.push_back(p.first);
			v.push_back(p.first);
		}
		Ans = 999;
		for (int i = 0; i < v.size()-2; i++) {
			for (int j = i + 1; j < v.size() - 1; j++) {
				for (int k = j + 1; k < v.size(); k++) {
					int Ans_t = distance(v[i], v[j]);
					Ans_t += distance(v[j], v[k]);
					Ans_t += distance(v[k], v[i]);
					if (Ans > Ans_t) Ans = Ans_t;
				}
			}
		}
		cout << Ans << '\n';
	}
	return 0;
}

int distance(string a, string b) {
	int d = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) d++;
	}
	return d;
}