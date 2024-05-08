#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[9];
int c[9];
int result[9];
vector<vector<int>> ans;

void permutation(int n, int d) {
	result[d] = arr[n];
	if (d == M) {
		vector<int> temp;
		for (int i = 1; i <= M; i++) temp.push_back(result[i]);
		ans.push_back(temp);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (c[i] > 0) {
			c[i]--;
			permutation(i, d + 1);
			c[i]++;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		c[i]++;
	}

	sort(arr + 1, arr + N + 1);
	permutation(0, 0);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (vector<int> t : ans) {
		for (int i = 0; i < t.size(); i++) {
			cout << t[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
//include <bits/stdc++.h>
//using namespace std;
//
//int N, M;
//vector<int> vec(8);
//
//void makeArr(vector<int> , vector<int> , int );
//
//int main() {
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		cin >> vec[i];
//	}
//	sort(vec.begin(), vec.begin() + N);
//
//	vector<int> rar = vec;
//	vector<int> arr(8);
//
//	makeArr(arr, rar, 0);
//
//	return 0;
//}
//
//void makeArr(vector<int> arr, vector<int> rar, int length) {
//	if (length >= M) {
//		for (int i = 0; i < length; i++) {
//			cout << arr[i] << " ";
//		}
//		cout << '\n';
//		return;
//	}
//	int before = 0;
//	for (int i = 0; i < rar.size(); i++) {
//		if (rar[i] != 0 && before != rar[i]) {
//			arr[length] = rar[i];
//			rar[i] = 0;
//			makeArr(arr, rar, length + 1);
//			rar[i] = arr[length];
//			before = rar[i];
//		}
//	}	
//}