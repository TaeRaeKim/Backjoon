// 문제 시작시간 : 1203
// 풀이 완료시간 :  
// 스스로 풀었는가  

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int avg(double s, int n);
int mid(int n);
int mod();
int rng();

vector<int> arr(500000);
map<int, int> m;
pair<int, int> v;
double sum = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		m[arr[i]]++;
	}
	int i = 0;
	for (pair<int, int> p : m) {
		if (v.second < p.second) v.second = p.second;
		for (int j = 0; j < p.second; j++) {
			sum += p.first;
			arr[i++] = p.first;
		}
	}

	cout << avg(sum, N) << '\n';
	cout << mid(N) << '\n';
	cout << mod() << '\n';
	cout << rng() << '\n';

	return 0;
}

int avg(double s, int n) {
	if (s > 0) s = (s / n) * 10 + 5;
	else s = (s / n) * 10 - 5;
	return s / 10;
}

int mid(int n) {
	return arr[n / 2];
}

int mod() {
	int c = 0;
	bool tf = false;

	for (pair<int, int> p : m) {
		if (v.second == p.second) {
			v.first = p.first;
			c++;
			if (c >= 2) break;
		}
	}

	return v.first;
}
int rng() {
	int min = m.begin()->first;
	int max = (--m.end())->first;
	return max - min;
}
