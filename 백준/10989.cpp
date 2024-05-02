#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int N, number;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> number;
		arr[number-1]++;
	}
	
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i+1 << '\n';
		}
	}
	return 0;
}