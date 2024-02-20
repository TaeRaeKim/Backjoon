// 문제 시작시간 : 1236
// 풀이 완료시간 :
// 스스로 풀었는가 : O
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> str;
bool compare(string, string);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		str.push_back(s);
	}
	sort(str.begin(), str.end(), compare);
	string before = "";
	for (string s : str) {
		if(s.compare(before)!=0)cout << s << endl;
		before = s;
	}

	return 0;
}

bool compare(string a, string b) {
	if (a.length() < b.length()) return true;
	else if (a.length() > b.length()) return false;
	else {
		return a.compare(b) < 0 ? true : false;
	}
}