#include <bits/stdc++.h>
using namespace std;

int N, M, needMoney, money, friends[10001], prices[10001];

int find(int v) {
	if (friends[v] == v) return v;
	friends[v] = find(friends[v]);
	return friends[v];
}
void friendShip(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	friends[u] = friends[v];
	prices[v] = min(prices[u], prices[v]);
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> money;
	for (int i = 1; i <= N; i++) {
		cin >> prices[i];
		friends[i] = i;
	}

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		friendShip(u, v);
	}

	for (int i = 1; i <= N; i++) if (friends[i] == i) needMoney += prices[i];

	cout << (money < needMoney ? "Oh no" : to_string(needMoney));

	return 0;
}