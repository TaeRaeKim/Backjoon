#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int sum = 0;
	int n, i;
	for(int n=0; n<5; n++){
		cin >> i;
		sum += pow(i, 2);
	}
	cout << sum % 10 << '\n';

	return 0;
}