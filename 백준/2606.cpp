#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<set<int>> arr(101);
queue<int> q;
bool visit[101];
int f = 0;
int N, M, Answer = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;
	cin >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a].insert(b);
		arr[b].insert(a);
	}
	visit[1] = true;
	q.push(1);	
	
	while (!q.empty()) {
		f = q.front();
		q.pop();
		for (int t : arr[f]) {
			if (!visit[t]) {
				q.push(t);
				Answer++;
				visit[t] = true;
			}			
		}
	}
	cout << Answer;

	return 0;
}