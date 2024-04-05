#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N;
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	priority_queue<pii> pq;
	
	cin >> N;
	int d, w;
	for (int i = 0; i < N; i++) {
		
		cin >> d >> w;
		pq.push(make_pair(w, d));
	}

	//first=score, second=day
	while (!pq.empty()) {
		pii t = pq.top(); pq.pop();
		for (int i = t.second; i >= 1; i--) {
			if (arr[i] == 0) {
				arr[i] = t.first;
				break;
			}			
		}
	}
	int score = 0;
	for (int i = 1; i <= 1000; i++) {
		score += arr[i];
	}
	cout << score;

	return 0;
}