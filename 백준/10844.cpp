#include <iostream>
using namespace std;

class Dynamic {
public :
	int value = 0;
	int count[10] = { 0, };
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;

	Dynamic D[101];
	for (int i = 1; i < 10; i++) {
		D[1].count[i] = 1;
	}
	D[1].value = 9;

	for (int n = 2; n <= N; n++) {
		for (int i = 0; i <= 9; i++) {
			//D[n].count[x] => 길이N의 끝자리가 x인 계단수의 개수 
			//0
			if (i == 0) D[n].count[i] = D[n - 1].count[1];
			//9
			else if (i==9) D[n].count[i] = D[n - 1].count[8];
			//1~8
			else D[n].count[i] = (D[n - 1].count[i - 1] + D[n - 1].count[i + 1]) % 1000000000;

			D[n].value = (D[n].value +D[n].count[i]) % 1000000000;
		}
	}
	cout << D[N].value << '\n';

	return 0;
}

