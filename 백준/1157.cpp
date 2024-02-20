#include <iostream>
#include <string>
using namespace std;

//a A 97 65
//z Z 122 90
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	getline(cin, str);


	int az[26] = { 0, };
	
	for (int i = 0; i < str.length(); i++) {
		str[i] - 'a' < 0 ? ++az[str[i] - 'A'] : ++az[str[i] - 'a'];
	}
	int m = 0, c = 0, k = 0;
	for (int i = 0; i < 26; i++) {
		if (az[i] == 0) continue;

		else if (m < az[i]) {
			m = az[i];
			k = i;
			c = 1;
		}
		else if (m == az[i]) c++;
	}

	if (c == 1) cout << (char)(k + 65) << '\n';
	else cout << "?" << '\n';

	return 0;
}

