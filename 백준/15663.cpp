#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> vec(8);

void makeArr(vector<int> , vector<int> , int );

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.begin() + N);

	vector<int> rar = vec;
	vector<int> arr(8);

	makeArr(arr, rar, 0);

	return 0;
}

void makeArr(vector<int> arr, vector<int> rar, int length) {
	if (length >= M) {
		for (int i = 0; i < length; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	int before = 0;
	for (int i = 0; i < rar.size(); i++) {
		if (rar[i] != 0 && before != rar[i]) {
			arr[length] = rar[i];
			rar[i] = 0;
			makeArr(arr, rar, length + 1);
			rar[i] = arr[length];
			before = rar[i];
		}
	}	
}