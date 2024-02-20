#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int count = 0;
	
	int c=0, i=0;
	getline(cin, str);

	
	while (string::npos != (i = str.find(" ", i))) {
		i++; c++;
	}

	if (str[str.length() - 1] == ' ') c--;
	if (str[0] == ' ') c--;

	cout << c+1 << '\n';

	return 0;
}

