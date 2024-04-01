#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, string> account;
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin.ignore();
	string line;
	int index = 0;
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		index = line.find(" ");
		account.insert(make_pair(line.substr(0, index), line.substr(index + 1, line.length())));
	}

	for (int i = 0; i < M; i++) {
		getline(cin, line);
		cout << account[line] << '\n';
	}

	return 0;
}