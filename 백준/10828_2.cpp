#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define PUSH 1
#define POP 2
#define SIZE 3
#define EMPTY 4
#define TOP 5

class Stack {
private:
	int _data[10000];
	int _size;
public:
	int push(int);
	int pop();
	int size();
	int empty();
	int top();
	Stack() {
		_size = 0;
	}
};

vector<string> split(string str, string w);
int check_command(string str);
void print(int i);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int TC;
	string s_command;
	Stack stack;
	getline(cin, s_command);
	TC=std::stoi(s_command);
	
	for (int T = 0; T < TC; T++) {
		getline(cin, s_command);
		vector<string> vec = split(s_command, " ");
		int command = check_command(vec.front());
		if (PUSH == command)		stack.push(std::stoi(vec.back()));
		else if (POP == command)	print(stack.pop());
		else if (SIZE == command)	print(stack.size());
		else if (EMPTY == command)	print(stack.empty());
		else if (TOP == command)	print(stack.top());
	}
	return 0;
}

int Stack::push(int value) {
	if (_size == 10000) {
		return -1;
	}
	_data[_size] = value;
	_size++;
	return 0;
}

int Stack::pop() {
	if (_size <= 0) return -1;
	else return _data[--_size];
}

int Stack::size() {
	return _size;
}

int Stack::empty() {
	return _size == 0 ? true : false;
}

int Stack::top() {
	if (_size <= 0) return -1;
	return _data[_size-1];
}

//----------------------------------

vector<string> split(string str, string w) {
	int current = 0;
	int previous = 0;
	vector<string> vec;
	while (string::npos != (current = str.find(w, previous))) {
		vec.push_back(str.substr(previous, current - previous));
		previous = current + 1;
	}
	vec.push_back(str.substr(previous, current - previous));

	return vec;
}

int check_command(string str) {
	if (str.compare("push") == 0) return 1;
	if (str.compare("pop") == 0) return 2;
	if (str.compare("size") == 0) return 3;
	if (str.compare("empty") == 0) return 4;
	if (str.compare("top") == 0) return 5;
}

void print(int i) {
	cout << i << '\n';
}