#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> D(1001);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int A[1001];
	cin >> A[1];
	D[1].push_back(A[1]);
	for (int i = 2; i <= N; i++) {
		cin >> A[i];
		int m=0,k=0;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				if (m < D[j].size()) {
					m = D[j].size();
					k = j;
				}
			}
		}
		D[i] = D[k];
		D[i].push_back(A[i]);
	}
	int m = 0, k = 0;
	for (int i = 1; i <= N; i++) {
		if (m < D[i].size()) {
			m = D[i].size();
			k = i;
		}
	}

	cout << m << '\n';
	for (int i = 0; i < D[k].size(); i++) {
		cout << D[k][i] << " ";
	}
	cout << '\n';
	

	return 0;
}
