#include <iostream>
#include <vector>
using namespace std;

#define R 0
#define G 1
#define B 2
#define TOTAL 3


int N;
int rgb[3];
int _rgb[3];
int temp[4];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> rgb[R] >> rgb[G] >> rgb[B];

	temp[TOTAL] = min(rgb[R], min(rgb[G], rgb[B]));
	_rgb[R] = rgb[R];
	_rgb[G] = rgb[G];
	_rgb[B] = rgb[B];

	for (int i = 2; i <= N; i++) {
		cin >> rgb[R] >> rgb[G] >> rgb[B];
		temp[R] = min(_rgb[G] + rgb[R], _rgb[B] + rgb[R]);
		temp[G] = min(_rgb[R] + rgb[G], _rgb[B] + rgb[G]);
		temp[B] = min(_rgb[R] + rgb[B], _rgb[G] + rgb[B]);

		temp[TOTAL] = min(temp[R], min(temp[G], temp[B]));

		_rgb[R] = temp[R];
		_rgb[G] = temp[G];
		_rgb[B] = temp[B];
	}
	cout << temp[TOTAL] << '\n';

	return 0;
}