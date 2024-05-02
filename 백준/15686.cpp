#include <bits/stdc++.h>
using pos = pair<int, int>;
using namespace std;

int N, M;
vector<pos> home;
vector<pos> chicken;
int ans[100];
int maxChicken = 0;
int main() {
	cin >> N >> M;

	int point;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> point;
			if (point == 1) home.push_back(pos(i, j));
			else if (point == 2) {
				chicken.push_back(pos(i, j));
				maxChicken++;
			}
		}
	}


	return 0;
}