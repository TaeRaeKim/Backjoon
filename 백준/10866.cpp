#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define DQ_MAX_SIZE 10000

#define PUSH_FRONT 1
#define PUSH_BACK 2
#define POP_FRONT 3
#define POP_BACK 4
#define SIZE 5
#define EMPTY 6
#define FRONT 7
#define BACK 8

class Deque {
public:
	int push_front(int);
	int push_back(int);
	int pop_front();
	int pop_back();
	int size();
	bool empty();
	int front();
	int back();
private:
	int f = DQ_MAX_SIZE-1, r = DQ_MAX_SIZE;
	int arr[DQ_MAX_SIZE*2];
	int _size = 0;
};

vector<string> split(string, string);
int getCommand(string);
void print(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Deque dq;
	int N;
	cin >> N;
	cin.ignore();
	string s_command;
	int command;
	vector<string> v_command;
	for (int i = 0; i < N; i++) {
		getline(cin, s_command);
		v_command = split(s_command, " ");
		command = getCommand(v_command[0]);

		if (command == PUSH_FRONT) {
			dq.push_front(stoi(v_command[1]));
		}
		else if (command == PUSH_BACK) {
			dq.push_back(stoi(v_command[1]));
		}
		else if (command == POP_FRONT) {
			print(dq.pop_front());
		}
		else if (command == POP_BACK) {
			print(dq.pop_back());
		}
		else if (command == SIZE) {
			print(dq.size());
		}
		else if (command == EMPTY) {
			print((int)dq.empty());
		}
		else if (command == FRONT) {
			print(dq.front());
		}
		else if (command == BACK) {
			print(dq.back());
		}
	}
}

vector<string> split(string str, string f) {
	vector<string> v;
	int prev = 0;
	int i = 0;
	while (string::npos != (i = str.find(f, prev))) {
		v.push_back(str.substr(prev, i - prev));
		prev = i + 1;
	}
	v.push_back(str.substr(prev, i - prev));
	return v;
}

int Deque::push_front(int n) {
	if (_size == DQ_MAX_SIZE) return -1;
	arr[f] = n;
	f--; _size++;
	if (f == -1) f = (DQ_MAX_SIZE * 2) - 1;
	return 0;
}

int Deque::push_back(int n) {
	if (_size == DQ_MAX_SIZE) return -1;
	arr[r] = n;
	r++; _size++;
	if (r == (DQ_MAX_SIZE * 2)) r = 0;
	return 0;
}

int Deque::pop_front() {
	if (_size == 0) return -1;
	f++; _size--;
	if (f == (DQ_MAX_SIZE * 2)) f = 0;
	int value = arr[f];
	return value;
}

int Deque::pop_back() {
	if (_size == 0) return -1;
	r--; _size--;
	if (r < 0) r = (DQ_MAX_SIZE * 2) - 1;
	int value = arr[r];
	return value;
}

int Deque::size() {
	return _size;
}

bool Deque::empty() {
	return _size == 0 ? true : false;
}

int Deque::front() {
	
	return _size > 0 ? f+1== (DQ_MAX_SIZE * 2) ?arr[0]:arr[f+1] : -1;
}

int Deque::back() {
	return _size > 0 ? r-1==-1 ? arr[(DQ_MAX_SIZE * 2)-1]:arr[r-1] : -1;
}

int getCommand(string str) {
	if (str.compare("push_front") == 0) return PUSH_FRONT;
	if (str.compare("push_back") == 0) return PUSH_BACK;
	if (str.compare("pop_front") == 0) return POP_FRONT;
	if (str.compare("pop_back") == 0) return POP_BACK;
	if (str.compare("size") == 0) return SIZE;
	if (str.compare("empty") == 0) return EMPTY;
	if (str.compare("front") == 0) return FRONT;
	if (str.compare("back") == 0) return BACK;
	return -1;
}

void print(int i) {
	cout << i << '\n';
}
