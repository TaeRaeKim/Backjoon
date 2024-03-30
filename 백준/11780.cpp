#include <bits/stdc++.h>
using namespace std;

#define INF 100000 * 100

int N, M, sp, ep, v;
int arr[101][101];
vector<int> var[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;

	//Initilize
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j] = INF;
			if (i == j) arr[i][j] = 0;
		}
	}

	//Input
	for (int i = 0; i < M; i++) {
		cin >> sp >> ep >> v;
		if (arr[sp][ep] > v) {
			arr[sp][ep] = min(arr[sp][ep], v);

			var[sp][ep].clear();
			var[sp][ep].push_back(sp);
			var[sp][ep].push_back(ep);
		}
	}

	//Solve
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					// min cost 
					arr[i][j] = arr[i][k] + arr[k][j]; 

					// shortest path
					var[i][j] = var[i][k];
					var[i][j].insert(var[i][j].end(), var[k][j].begin() + 1, var[k][j].end());
				}

			}
		}
	}

	//Output min cost
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cout << (arr[i][j] == INF ? 0 : arr[i][j]) << " ";
		cout << '\n';
	}

	//Output shortest path
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << var[i][j].size() << " ";
			for (int k : var[i][j]) cout << k << " ";
			cout << '\n';
		}
	}

	return 0;
}