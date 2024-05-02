#include <bits/stdc++.h>
using namespace std;

int N;
int h, w, d, e, l, o, r;
set<int> s;

bool isSame() {
	return (N == (h * 10000 + e * 1000 + l * 120 + o * 1001 + w * 10000 + r * 100 + d));
}

int main() {
	cin >> N;

	for (int i = 0; i < 10000000; i++) {
		h = (i % 10000000) / 1000000;
		w = (i % 1000000) / 100000;
		d = (i % 100000) / 10000;
		e = (i % 10000) / 1000;
		l = (i % 1000) / 100;
		o = (i % 100) / 10;
		r = (i % 10);
		if (h == 0 || w == 0) continue;
		else if (isSame()) {
			s.clear();
			s.insert(h); s.insert(w); s.insert(d); s.insert(e); s.insert(l); s.insert(o); s.insert(r);
			if (s.size() == 7) {
				cout << "  " << h << e << l << l << o << '\n';
				cout << "+ " << w << o << r << l << d << '\n';
				cout << "-------\n";
				
				cout << setw(7) << N << '\n';
				return 0;
			}
		}
	}
	cout << "No Answer";

	return 0;
}