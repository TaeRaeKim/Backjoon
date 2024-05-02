#include <bits/stdc++.h>
using namespace std;
#define R 31
#define MOD 1234567891

int N;
string str;
long long int Hash;
int myPow(int r, int i) {
	long long int result = 1;
	for (int k = 0; k < i; k++) {
		result *= r;
		result %= MOD;
	}
	return result;
}
int main() {
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		Hash += ((long long int)myPow(R, i) * (str[i] - 'a' + 1));
		Hash %= MOD;
	}
	cout << Hash;
	return 0;
}