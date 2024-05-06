#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

int di[4] = { -1, 0, 1, 0 }, dj[4] = { 0, 1, 0, -1 };
int N, M, T;
int arr[50][50];
vector<pos> airCleaner;

bool isValid(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M) return false;
	return true;
}

void diffusion() {
	//먼지가 존재할 때 Queue에 등록
	queue<pair<pos, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] >= 5) {
				q.push(make_pair(pos(i, j), arr[i][j]));
			}
		}
	}

	int c, v, ni, nj;
	while (!q.empty()) {
		pos point = q.front().first;
		int value = q.front().second; q.pop();
		
		c = 0;
		v = value / 5;

		for (int k = 0; k < 4; k++) {
			ni = point.first + di[k], nj = point.second + dj[k];
			if (isValid(ni, nj) && arr[ni][nj] >= 0) {
				arr[ni][nj] += v;
				c++;
			}
		}
		arr[point.first][point.second] -= (v * c);
	}
}

pos MoveNext(pos cp, int direction) {
	if (direction == 0) {
		if (cp.second == 0 && cp.first > 0) cp.first--;
		else if (cp.first == 0 && cp.second < M - 1) cp.second++;
		else if (cp.second == M-1 && cp.first < airCleaner[0].first) cp.first++;
		else if (cp.first == airCleaner[0].first && cp.second > 0) cp.second--;
	}
	else if(direction == 1) {
		if (cp.second == 0 && cp.first < N-1) cp.first ++;
		else if (cp.first == N-1 && cp.second < M-1) cp.second++;
		else if (cp.second == M-1 && cp.first > airCleaner[1].first) cp.first--;
		else if (cp.first == airCleaner[1].first && cp.second > 0) cp.second--;
	}
	return cp;
}
void activateAC() {
	for (int i = 0; i < 2; i++) {
		pos CleanPoint = MoveNext(airCleaner[i], i);
		arr[CleanPoint.first][CleanPoint.second] = 0;

		pos NextCleanPoint = MoveNext(CleanPoint, i);
		do {
			arr[CleanPoint.first][CleanPoint.second] = arr[NextCleanPoint.first][NextCleanPoint.second];
			CleanPoint = NextCleanPoint;
			NextCleanPoint = MoveNext(CleanPoint, i);
		} while (NextCleanPoint != airCleaner[i]);
		arr[CleanPoint.first][CleanPoint.second] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) airCleaner.push_back(pos(i, j));
		}		

	for (int i = 0; i < T; i++) {
		diffusion();
		activateAC();
	}
	int Ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] > 0) Ans += arr[i][j];
		}
	}
	cout << Ans;
	return 0;
}

