#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100000

class Heap {
private:
	int _size = 0;
	int _data[MAX_SIZE + 1];
public:
	int push(int);
	int pop();
	void print();
};

int N, x;
Heap h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x != 0) {
			h.push(x);
			continue;
		}
		h.print();
		h.pop();		
	}
	return 0;
}

int Heap::push(int x) {
	if (_size == MAX_SIZE) {
		return -1;
	}
	int i = ++_size;
	_data[i] = x;

	while (i > 1) {
		if (_data[i] < _data[i / 2]) swap(_data[i], _data[i / 2]);
		else break;
		i = i / 2;
	}
	return 0;
}
int Heap::pop() {
	if (_size == 0) {
		return -1;
	}
	int v = _data[1];
	_data[1] = _data[_size];
	_data[_size--] = 0;

	int node = 1;
	int children = 2;
	bool right = false;
	while (children <= _size) {
		if (children + 1 <= _size) right = true;
		if (right) {
			children = _data[children] < _data[children + 1] ? children : children + 1;
		}
		if (_data[node] > _data[children]) swap(_data[node], _data[children]);

		node = children;
		children = node * 2;
		right = false;
	}
	return v;
}

void Heap::print() {
	cout << (_size > 0 ? _data[1] : 0) << '\n';
}