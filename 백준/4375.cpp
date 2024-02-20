#include <iostream>
#include <cmath>
using namespace std;

int find111(int n);
int main() {
	/*
	2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.
	1 초
	128 MB
	*/
	int n;
	while (cin >> n) cout << find111(n) <<'\n';

}

int find111(int n){
	int i = 1;
	int a = 1;

	while (true) {
		if (a % n == 0) return i;
		else {
			a = a * 10 + 1;
			a = a % n;
			i++;
		}
	}
}