#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<int, int> sS;

int soinsu(int n);
int main() {
	/*
	양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오
	2 초
	512 MB

	첫째 줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다. 1,000,000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.
	첫째 줄에 N을 출력한다. N은 항상 32비트 부호있는 정수로 표현할 수 있다.
	*/

	int n;
	int A = 1;
	int N[50];
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
		soinsu(N[i]);
	}

	for (pair<int, int> s : sS) {
		A *= pow(s.first, s.second);
	}
	for (int i = 0; i < n; i++) {
		if (A == N[i]) {
			A *= sS.begin()->first;
		}
	}
	cout << A;
}

int soinsu(int n) {
	int c = 2;
	map<int, int> S;
	while (1) {
		if (n / c == 1 && n% c == 0) {
			S[c] = S[c] + 1;
			break;
		}

		if (n % c == 0) {
			S[c] = S[c] + 1;
			n /= c;
		}
		else c++;
	}

	for (pair<int, int> s : S) {
		if (sS[s.first] < S[s.first]) sS[s.first] = S[s.first];
	}

	return 0;
}
