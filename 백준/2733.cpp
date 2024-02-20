#include <iostream>
#include <string>
#include <deque>
using namespace std;

#define MAX 32768
#define IP 1
#define DP 2
#define IV 3
#define DV 4
#define PRT 5
#define ZP 6
#define NZP 7
#define ZS 8
#define PROGRAM_MAX 128000

class BrainFuck {
private:
	int pointer = 1;
	unsigned char data[MAX];
public:
	void increasePtr();
	void decreasePtr();
	void increaseValue();
	void decreaseValue();
	void print();
	void zeroPtr(char);
	void nozeroPtr();
	deque<char> dq;
	bool activateDq = false;
	int move = 0;
};

int getCommand(char);
BrainFuck bf;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int N;
	cin >> N;
	cin.ignore();
	int pivot = 0;
	int cmd;
	string str;
	getline(cin, str);
	for (int i = 0; i < N; i++) {
		while (str[pivot] != 'e') {
			cmd = getCommand(str[pivot]);
			switch (cmd) {
			case IP:
				if (bf.activateDq)bf.dq.push_back(str[pivot]);
				else if (bf.move > 0);
				else  bf.increasePtr();
				break;
			case DP:
				if (bf.activateDq)bf.dq.push_back(str[pivot]);
				else if (bf.move > 0);
				else bf.decreasePtr();
				break;
			case IV:
				if (bf.activateDq)bf.dq.push_back(str[pivot]);
				else if (bf.move > 0);
				else bf.increaseValue();
				break;
			case DV:
				if (bf.activateDq)bf.dq.push_back(str[pivot]);
				else if (bf.move > 0);
				else bf.decreaseValue();
				break;
			case PRT:
				if (bf.activateDq)bf.dq.push_back(str[pivot]);
				else if (bf.move > 0);
				else bf.print();
				break;
			case ZP:
				bf.dq.push_back(str[pivot]);
				bf.zeroPtr(str[pivot]);
				break;
			case NZP:
				bf.nozeroPtr();
				break;
			case ZS:
				pivot = 0;
				getline(cin, str);
				break;
			}
			if (++pivot == str.size()) getline(cin, str);
		}
	}

	return 0;
}
void BrainFuck::increasePtr() {
	if (++pointer >= 32767) pointer = 0;
}
void BrainFuck::decreasePtr() {
	if (--pointer <= 0) pointer = 0;
}
void BrainFuck::increaseValue() {
	if (++data[pointer] > 255) data[pointer] = 0;
}
void BrainFuck::decreaseValue() {
	if (--data[pointer] < 0) data[pointer] = 255;
}
void BrainFuck::print() {
	cout << (char)data[pointer];
}
void BrainFuck::zeroPtr(char c) {
	if (data[pointer] == 0) {
		bf.move++;
	}
}
void BrainFuck::nozeroPtr() {
	deque<char> d;
	char c = 0;
	while (!dq.empty() && c!='[') {
		c = dq.back();
		dq.pop_back();
		d.push_front(c);
	}

	if (d.front() == '[') {

	}
	bf.move--;
}

int getCommand(char c) {
	if (c == '>') return IP;
	if (c == '<') return DP;
	if (c == '+') return IV;
	if (c == '-') return DV;
	if (c == '.') return PRT;
	if (c == '[') return ZP;
	if (c == ']') return NZP;
	if (c == '%') return ZS;
}