#include <iostream>
#include <stack>
using namespace std;

void print(string str);
void print(int i);

int main() {
	stack<int> s;
	int N;
	cin >> N;

	int index = 1;
	int arr[100000] = {};
	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;

		if (index <= M) {
			while (index <= M) {
				s.push(index++);
				arr[i]++;
			}
			s.pop();
		}
		else if (index > M) {
			if ( s.top() != M || s.empty()) {
				print("NO");
				return 0;
			}
			else if (s.top() == M) {
				s.pop();
				arr[i] = 0;
			}
		}
	}
	if (s.empty()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < arr[i]; j++) {
				print("+");
			}
			print("-");
		}
	}
	else print("NO");

	return 0;
}

void print(string str) {
	cout << str << '\n';
}
void print(int i ) {
	cout << i << '\n';
}