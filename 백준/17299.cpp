#include <iostream>
#include <stack>
using namespace std;

int answer[1000000]; //����迭
int num[1000001] = {}; //�� ���� ���� Ƚ�� ex) num[100]�� 100�� ����Ƚ��, �߰��� ������� �� �ִ�.
int arr[1000000]; //�Է°�

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	stack<int> s;
	
	int N, v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;
		arr[i] = v;
		num[v]++;
	}

	for (int i = 0; i < N; i++) {
		while (!s.empty() && num[arr[s.top()]] < num[arr[i]]) {
			answer[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < N - 1; i++) {
		cout << answer[i] << " ";
	}
	cout << answer[N - 1] << '\n';

	return 0;
}
