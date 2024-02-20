#include <iostream>
#include <stack>
using namespace std;

class Point {
public :
	int key;
	int value;
	Point(int key, int value) {
		this->key = key; this->value = value;
	}
};

int arr[1000000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<Point> s;

	int N;
	int v;
	cin >> N;
	cin >> v;
	s.push(Point(0, v));
	for (int n = 1; n < N; n++) {
		cin >> v;FileName
		while (!s.empty() && s.top().value < v ) {
			arr[s.top().key] = v;
			s.pop();
		}
		s.push(Point(n, v));
	}
	while (!s.empty()) {
		arr[s.top().key] = -1;
		s.pop();
	}
	
	for (int i = 0; i < N-1; i++) {
		cout << arr[i] << " ";
	}
	cout << arr[N - 1] << '\n';

	return 0;
}
