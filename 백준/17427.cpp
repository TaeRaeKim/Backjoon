#include <iostream>
using namespace std;

long long int m(int n);
int main() {
	int N;
	cin >> N;
	cout << m(N) <<"\n";	
}

long long int m(int n) {
	long long int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i * (n / i);
	}
	return sum;
}