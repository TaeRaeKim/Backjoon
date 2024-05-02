#include <bits/stdc++.h>
using namespace std;
using Task = pair<int, int>;


int N;
bool task;
int score, minute, answer;
stack<Task> s;
Task top;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> task;
		if (task) {
			cin >> score >> minute;
			if (minute > 1) s.push(Task(score, minute - 1));
			else answer += score;
		}
		else if (!s.empty()) {			
			s.top().second--;
			if (s.top().second == 0) {
				answer += s.top().first;
				s.pop();
			}
		}
	}
	cout << answer;

	return 0;
}