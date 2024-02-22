#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[5] = { {1,4},{4,1},{2,2},{2,3},{3,2} };

int arr[500][500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int Ans = 0;
	int tmax;
	vector<int> tvec;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 5; k++) {
				if (
					i + p[k].first > N ||
					j + p[k].second > M
					) continue;
				tmax = 0;
				tvec.clear();
				for (int l = 0; l < p[k].first; l++) {
					for (int m = 0; m < p[k].second; m++) {
						tvec.push_back(arr[i + l][j + m]);
						tmax += arr[i + l][j + m];
					}
				}
				if (tvec.size() == 6) {
					//6개를 줄세운다.
					sort(tvec.begin(), tvec.end());
					tmax = tmax - tvec[0] - tvec[1];

					vector<int> ttvec;
					if (k == 3) {
						ttvec.push_back(
							arr[i][j + 1] < arr[i + 1][j + 1] ? arr[i][j + 1] : arr[i + 1][j + 1]
						);
						ttvec.push_back(
							arr[i][j + 1] > arr[i + 1][j + 1] ? arr[i][j + 1] : arr[i + 1][j + 1]
						);
					}
					else {
						ttvec.push_back(
							arr[i + 1][j] < arr[i + 1][j + 1] ? arr[i + 1][j] : arr[i + 1][j + 1]
						);
						ttvec.push_back(
							arr[i + 1][j] > arr[i + 1][j + 1] ? arr[i + 1][j] : arr[i + 1][j + 1]
						);
					}
					if ((tvec[0] == ttvec[0]) && (tvec[1] == ttvec[1])) {
						tmax = max(tmax - tvec[3] + tvec[0], tmax - tvec[3] + tvec[1]);
					}
				}
				if (Ans < tmax) {
					Ans = tmax;
				}
			}
		}
	}
	cout << Ans;
	return 0;
}