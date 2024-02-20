#include <iostream>
#include <list>
#include <string>
using namespace std;

#define PUSH 1
#define POP 2
#define SIZE 3
#define EMPTY 4
#define FRONT 5
#define BACK 6

class Queue {
private :
	list<int> data;
public:
	void push(int);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
};

int check_command(string);
void print();
void print(int);
void print(string);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	string str_command;
	int command, v;
	Queue q;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str_command;
		command = check_command(str_command);

		if (command == PUSH) {
			cin >> v;
			q.push(v);
		}
		else if (command == POP) {
			print(q.pop());
		}
		else if (command == SIZE){
			print(q.size());
		}
		else if (command == EMPTY) {
			print(q.empty());
		}
		else if (command == FRONT) {
			print(q.front());
		}
		else if (command == BACK) {
			print(q.back());
		}
	}

	return 0;
}

void Queue::push(int v) {
	data.push_back(v);
}
int Queue::pop() {
	if (data.empty()) return -1;
	int v = data.front();
	data.pop_front();
	return v;
}
int Queue::size() {
	return data.size();
}
bool Queue::empty() {
	return data.empty();
}
int Queue::front() {
	if (data.empty()) return -1;
	return data.front();
}
int Queue::back() {
	if (data.empty()) return -1;
	return data.back();
}

int check_command(string str) {
	if (str.compare("push") == 0) return 1;
	if (str.compare("pop") == 0) return 2;
	if (str.compare("size") == 0) return 3;
	if (str.compare("empty") == 0) return 4;
	if (str.compare("front") == 0) return 5;
	if (str.compare("back") == 0) return 6;
}

void print(string str) {
	cout << str << '\n';
}
void print() {
	cout << '\n';
}
void print(int i) {
	cout << i << '\n';
}