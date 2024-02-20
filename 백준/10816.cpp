#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int N, M, temp;
map<int, int> m;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//cin >> N;
	//for (int i = 0; i < N; i++) {
	//	cin >> temp;
	//	m[temp]++;
	//}

	//cin >> M;
	//for (int i = 0; i < M; i++) {
	//	cin >> temp;
	//	cout << m[temp] << " ";
	//}
	// 
	//----------------------------------------------------
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		cout << distance(
			lower_bound(v.begin(), v.end(), temp),
			upper_bound(v.begin(), v.end(), temp)) 
			<< " ";
	}
	return 0;
}
