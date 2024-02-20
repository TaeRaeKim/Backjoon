// 문제 시작시간 : 1236
// 풀이 완료시간 :
// 스스로 풀었는가 : O
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const string,const string);
void print(string);

int N;
vector<string> v(20000);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.begin() + N, compare);

	print(v[0]);
	for (int i = 1; i < N; i++) {
		if (v[i - 1].compare(v[i]) != 0) print(v[i]);
		else continue;
	}
	return 0;
}

bool compare(const string a, const string b) {
	if (a.length() < b.length()) return true;
	else if (a.length() > b.length()) return false;
	else return a.compare(b) < 0 ? true : false;
}
void print(string str) {
	cout << str << '\n';
}