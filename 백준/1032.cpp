#include<iostream>
#include<string>
#include<algorithm>;
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<string> str(50);
	string answer = "";
	for (int n = 0; n < N; n++) {
		cin >> str[n];
		if (n == 0) {
			answer = str[n];
		}
		else {
			for (int i = 0; i < min(answer.size(), str[n].size()); i++) {
				if (answer[i] != str[n][i]) answer[i] = '?';
			}
			
		}
	}
	cout << answer << '\n';

}