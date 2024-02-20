#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N, M;
map<string, int> m;
vector<string> v;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N+M; i++) {
		cin >> str;
		m[str]++;
	}
	for (pair<string, int> t : m) {
		if (t.second > 1) v.push_back(t.first);
	}
	cout << v.size() << '\n';
	for (string t : v) {
		cout << t << '\n';
	}

	return 0;
}