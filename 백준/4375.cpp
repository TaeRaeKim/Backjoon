#include <iostream>
#include <cmath>
using namespace std;

int find111(int n);
int main() {
	/*
	2�� 5�� ������ �������� �ʴ� ���� n(1 �� n �� 10000)�� �־����� ��, �� �ڸ����� ��� 1�θ� �̷���� n�� ����� ã�� ���α׷��� �ۼ��Ͻÿ�.
	1 ��
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