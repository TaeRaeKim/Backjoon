#include <iostream>
using namespace std;

bool visit[1000];
int arr[1000][1000];

int N, M;
bool dfs(int i) {
	if (visit[i]) return 0;
	visit[i] = true;
	for (int j = 0; j < 1000; j++) {
		if (arr[i][j] == 1) {
			dfs(j);
		}
	}
	return true;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> N >> M;

	int p1, p2;
	for (int i = 0; i < M; i++) {
		cin >> p1 >> p2;
		arr[p1-1][p2-1] = 1;
		arr[p2-1][p1-1] = 1;
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += dfs(i);
	}
	cout << sum;
	return 0;
}