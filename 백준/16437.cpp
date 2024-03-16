#include <bits/stdc++.h>
using namespace std;
#define MAX 123456 + 1

class Land {
public:
	list<Land*> childs;
	long long int sheep;
	long long int wolves;
	void Initialize(char type, int count) {
		if (type == 'W') {
			sheep = 0;
			wolves = count;
		}
		else {
			sheep = count;
			wolves = 0;
		}
	}
};

int Lcount;
char t;
int c, n;
vector<Land> land(MAX);

void solve(Land* parent, Land* me) {
	for (Land* t : me->childs) {
		solve(me, t);
	}
	if (parent != nullptr) {
		parent->sheep += max((long long)0, me->sheep - parent->wolves);
		parent->wolves = max((long long)0, parent->wolves - me->sheep);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> Lcount;
	for (int i = 2; i <= Lcount; i++) {
		cin >> t >> c >> n;
		land[i].Initialize(t, c);
		land[n].childs.push_back(&land[i]);
	}
	solve(nullptr, &land[1]);
	cout << land[1].sheep;

	return 0;
}