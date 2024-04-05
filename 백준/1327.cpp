#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> um;
queue<pair<string,int>> q;
int N, K, t;
bool isSorted(string str) {
	for (int i = 0; i < str.length()-1; i++) {
		if (str[i] > str[i + 1]) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> K;
	char c;
	string s = "";
	
	for (int i = 0; i < N; i++) {
		cin >> c;
		s += c;
	}
	um.insert(make_pair(s, true));
	q.push(make_pair(s,0));
	while (!q.empty()) {
		string ts = q.front().first;
		int ti = q.front().second; q.pop();
		if (isSorted(ts)) {
			cout << ti;
			return 0;
		}
		for (int i = 0; i <= N - K; i++) {
			string tts = ts;
			reverse(tts.begin()+i, tts.begin()+i + K);
			if (!um[tts]) {
				um[tts] = true;
				q.push(make_pair(tts, ti + 1));
			}
		}
	}
	cout << -1;
	return 0;
}