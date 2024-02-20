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
	vector<int> _data;
public:
	Stack() {};
	void push(int);
	int pop();
	bool empty();
	int top();
	int size();
};

int check_command(string command);
vector<string> split(string str, string ch);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack stack;
	string str_command;
	int command;
	int N;
	cin >> N;
	getline(cin, str_command);

	for (int T = 0; T < N; T++) {
		getline(cin, str_command);
		command = check_command(str_command);
		if (command == PUSH) {
			stack.push(std::stoi(split(str_command, " ").back()));			
		}
		if (command == POP) {
			cout << stack.pop() << '\n';
		}
		if (command == SIZE) {
			cout << stack.size() << '\n';
		}
		if (command == EMPTY) {
			if (stack.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		if (command == TOP) {
			cout << stack.top() << '\n';
		}
	}

	return 0;
}

void Stack::push(int value) {
	_data.push_back(value);
}

int Stack::pop() {
	if (_data.size() == 0) {
		return -1;
	}
	int value = _data.back();
	_data.pop_back();
	return value;
}

bool Stack::empty() {
	return _data.size() == 0 ? true : false;
}

int Stack::top() {
	if (_data.size() == 0) return -1;
	return _data.back();
}

int Stack::size() {
	return _data.size();
}

int check_command(string command) {
	if (command.rfind("push", 0) == 0) return PUSH;
	else if (command.rfind("pop", 0) == 0) return POP;
	else if (command.rfind("size", 0) == 0) return SIZE;
	else if (command.rfind("empty", 0) == 0) return EMPTY;
	else if (command.rfind("top", 0) == 0) return TOP;
	return -1;
}

/// <summary>
/// substr은 시작점, 길이 
/// current - previous를 했을때 그 구간의 길이가 됨 
/// ex))
/// a_bb_ccc_dddd
/// 두번째 _의 경우 previous = 2, current = 4
/// </summary>
vector<string> split(string str, string ch) {
	vector<string> vec;
	int current = 0, previous = 0;

	while (string::npos != (current = str.find(ch, previous))) {
		string substring = str.substr(previous, current - previous);
		vec.push_back(substring);
		previous = current + 1;
	}
	vec.push_back(str.substr(previous, current - previous));

	return vec;
}
