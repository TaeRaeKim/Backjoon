#include <bits/stdc++.h>
using namespace std;

int dk[6] = { 0, 0, 0, 0, -1, 1 };
int di[6] = { -1, 0, 1, 0, 0, 0 };
int dj[6] = { 0, 1, 0, -1, 0, 0 };

class V {
public:
	int k, i, j;
	int t;
	V(int k, int i, int j, int t) {
		this->k = k;
		this->i = i;
		this->j = j;
		this->t = t;
	}
};

short int arr[100][100][100];
int N, M, H, ans = 0;
int tomato = 0;
int ripeTomato = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >>N >> H;
	  
	queue<V> q;

	for (int k = 0; k < H; k++) for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		//0이 안익은거 1이 익은거
		cin >> arr[k][i][j];
		if (arr[k][i][j] == 1) {
			q.push(V(k, i, j, 0));
			ripeTomato++;
		}
		if (arr[k][i][j] == 0) {
			ans = 0;
		}
		if (arr[k][i][j] != -1) tomato++;

	}

	while (!q.empty()) {
		V v = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			V np(v.k + dk[dir], v.i + di[dir], v.j + dj[dir], v.t + 1);
			if (np.k >= 0 && np.k < H && 
				np.i >= 0 && np.i < N &&
				np.j >= 0 && np.j < M &&
				arr[np.k][np.i][np.j] == 0
				) {

				ans = max(ans, np.t);
				ripeTomato++;
				arr[np.k][np.i][np.j] = 1;
				q.push(np);
			}
		}
	}

	if (ripeTomato == tomato) cout << ans;
	else cout << -1;

	return 0;
}