#include <bits/stdc++.h>
using namespace std;
using Place = pair<int, int>;

int di[] = { -1, 0 , 1 ,0 };
int dj[] = { 0 ,1, 0, -1 };

int N, M;
int arr[100][100];
int emptyPlace = 0;
queue<Place> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	int time = -1;
	while (emptyPlace != (N * M)) {
		emptyPlace = 1;
		int check[100][100] = { 0, };
		check[0][0] = -1;
		q.push(make_pair(0, 0));
		while (!q.empty()) {
			Place t = q.front(); q.pop();
			for (int k = 0; k < 4; k++) {
				int ni = t.first - di[k], nj = t.second - dj[k];
				if (ni >= 0 && ni < N &&
					nj >= 0 && nj < M ) {

					if (arr[ni][nj] == 0 && check[ni][nj] == 0) {
						check[ni][nj] = -1;
						emptyPlace++;
						q.push(make_pair(ni, nj));
					}
					else if (arr[ni][nj] == 1) {
						check[ni][nj]++;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (check[i][j] >= 2) arr[i][j] = 0;
		time++;
	}

	cout << time;
	return 0;
}