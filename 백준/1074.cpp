#include <iostream>
#include <cmath>
using namespace std;

int log2(int);

int main() {

	int N, x, y;
	int max;
	cin >> N >> x >> y;
	
	int answer = 0;
	int logx;
	int logy;

	while (x > 1) {
		logx= log2(x); //log(x)
		answer += 2 * pow(pow(2, logx), 2);
		x = x - pow(2,logx);
	}
	if (x == 0) answer += 0;
	else answer += 2;

	while (y > 1) {
		logy = log2(y); //log(y)
		answer += pow(pow(2, logy), 2);
		y = y - pow(2, logy);
	}
	if (y == 0) answer += 0;
	else answer += 1;

	cout << answer;

	return 0;
}


int log2(int n) {
	int v = 0;
	while (2 <= n) {
		n = n / 2;
		v++;
	}
	return v;
}