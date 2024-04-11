#include <bits/stdc++.h>
using namespace std;

int N;
string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> N;
	cin.ignore();
	for (int i = 1; i <= N; i++) {
		getline(cin, str);

		cout << i << ". " << str << '\n';
	}
	return 0;
}