#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using Color = pair<int, int>;

string color;
long long int sum = 0;
unordered_map<string, Color> um;
int main() {
	um["black"]		= Color(0, 1);
	um["brown"]		= Color(1, 10);
	um["red"]		= Color(2, 100);
	um["orange"]	= Color(3, 1000);
	um["yellow"]	= Color(4, 10000);
	um["green"]		= Color(5, 100000);
	um["blue"]		= Color(6, 1000000);
	um["violet"]	= Color(7, 10000000);
	um["grey"]		= Color(8, 100000000);
	um["white"]		= Color(9, 1000000000);

	cin >> color;
	sum += um[color].first * 10;
	cin >> color;
	sum += um[color].first;
	cin >> color;
	sum *= um[color].second;

	cout << sum;
	return 0;
}