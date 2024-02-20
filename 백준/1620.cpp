#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N, M;
vector<string> v(100000);
map<string, int> m;
string str;
int k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		m.insert(pair<string, int>(v[i], i));
	}

	cin.ignore();

	for (int i = 0; i < M; i++) {
		getline(cin, str);
		if (str[0] >= '0' && str[0] <= '9') {
			k = stoi(str) - 1;
			cout << v[k] << '\n';
		}
		else {
			cout << m[str] + 1 << '\n';
		}
	}
	return 0;
}