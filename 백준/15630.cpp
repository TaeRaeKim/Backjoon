// 문제 시작시간 : 1040
// 풀이 완료시간 : 
// 스스로 풀었는가 : 

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Dynamic {
public:
	string bin;
	int len;
	char ans;
	Dynamic() {
		bin = "0";
		len = 1;
		ans = '0';
	};
	Dynamic(string bin, int len, char ans) {
		this->bin = bin;
		this->len = len;
		this->ans = ans;
	};
};

int btoi(string);
string increaseBin(string);
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;

	vector<Dynamic*> D;
	D.push_back(new Dynamic());

	while (!(btoi(D.back()->bin) == N && D.back()->len == 1)) {
		Dynamic* p = D.back();

		D.push_back(new Dynamic());
		Dynamic* b = D.back();

		if (p->len - 1 == 0) {
			b->bin = increaseBin(p->bin);
			b->len = b->bin.length();
		}
		else {
			b->bin = p->bin;
			b->len = p->len - 1;
		}
		b->ans = b->bin[b->bin.length() - b->len];
	}
	for (Dynamic* d : D) {
		cout << d->ans;
	}
	cout << '\n';

	return 0;
}

int btoi(string str) {
	int sum = 0, pivot = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == '1') sum += pow(2, pivot);
		pivot++;
	}

	return sum;
}
string increaseBin(string str) {
	str[str.length() - 1]++;
	for (int i = str.length() - 1; i > 0; i--) {
		if (str[i] == '2') {
			str[i] = '0';
			str[i - 1]++;
		}
		else break;
	}
	if (str[0] == '2') {
		str[0] = '0';
		str = "1" + str;
	}
	return str;
}