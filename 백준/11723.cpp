#include <iostream>
#include <string>
using namespace std;

#define ADD 1
#define REMOVE 2
#define CHECK 3
#define TOGGLE 4
#define EMPTY 5
#define ALL 6

int getCommand(string);

bool arr[21];
int M;
string str;
int command, v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> str;
		command = getCommand(str);
		if (command <= TOGGLE) {
			cin >> v;
			if (command == ADD) arr[v] = true;
			else if (command == REMOVE) arr[v] = false;
			else if (command == CHECK) cout << (int)arr[v] << '\n';
			else if (command == TOGGLE) arr[v] = !arr[v];
		}
		else {
			for (int i = 1; i < 21; i++) {
				arr[i] = command - 5;
			}
		}
	}
	return 0;
}

int getCommand(string s) {
	if (s[0] == 'a' && s[1] == 'd') return ADD;
	if (s[0] == 'r') return REMOVE;
	if (s[0] == 'c') return CHECK;
	if (s[0] == 't') return TOGGLE;
	if (s[0] == 'e') return EMPTY;
	return ALL;
}