#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<int, int> sS;

int soinsu(int n);
int main() {
	/*
	��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�. � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�
	2 ��
	512 MB

	ù° �ٿ� N�� ��¥ ����� ������ �־�����. �� ������ 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� N�� ��¥ ����� �־�����. 1,000,000���� �۰ų� ����, 2���� ũ�ų� ���� �ڿ����̰�, �ߺ����� �ʴ´�.
	ù° �ٿ� N�� ����Ѵ�. N�� �׻� 32��Ʈ ��ȣ�ִ� ������ ǥ���� �� �ִ�.
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
