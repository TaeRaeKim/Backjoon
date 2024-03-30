#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using pii = pair<int, int>;

pii np[4][10] = { {{-1,1}, {-2,2}, {-3,3}, {-4,4}, {-5,5}, {-6,6}, {-7,7}, {-8,8}, {-9,9}, {-10,10}},
{ { 1,1 }, { 2,2 }, { 3,3 }, { 4,4 }, { 5,5 }, { 6,6 }, { 7,7 }, { 8,8 }, { 9,9 }, { 10,10 } },
{ { 1,-1 }, { 2,-2 }, { 3,-3 }, { 4,-4 }, { 5,-5 }, { 6,-6 }, { 7,-7 }, { 8,-8 }, { 9,-9 }, { 10,-10 } },
{ { -1,-1 }, { 2,-2 }, { -3,-3 }, { -4,-4 }, { -5,-5 }, { -6,-6 }, { -7,-7 }, { -8,-8 }, { -9,-9 }, { -10,-10 } } };

int N, v;
int ans = 0;

set<pii> arr;
map<pii, int> tarr;

int solve(pii t, int result) {
	tarr[t] = 1;
	//나를 포함시켰을때 최대값
	yes = solve(np, result+1);

	//나를 포함시키지 않았을때 최대값
	no = solve(np, result);
	tarr[t] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v;
			if (v == 1) arr.insert(make_pair(i, j));
		}
	}
	cout << ans;

	return 0;
}