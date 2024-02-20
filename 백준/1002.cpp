#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int TC;
	cin >> TC;

	int x1, y1, r1;
	int x2, y2, r2;
	int x, y;
	double distance;
	int answer = 0;

	for (int tc = 0; tc < TC; tc++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		distance = sqrt(pow(x1 -x2, 2) + pow(y1- y2, 2));

		if (x1 == x2 && y1 == y2 && r1 == r2) answer = -1;
		//else if (x1 == x2 && y1 == y2 && r1 != r2) answer = 0;

		else if (distance == r1 + r2) answer = 1;
		else if (r1 + r2 > distance && abs(r1 - r2) < distance) answer = 2;
		else if (abs(r1 - r2) == distance) answer = 1;
		else answer = 0;

		cout << answer << endl;
	}

	return 0;
}