#include <bits/stdc++.h>
using namespace std;

int N;
char arr[50][50];
int big = 0;

void changeUpDown(int i, int j);
void changeLeftRight(int i, int j);
void compareBig(int i, int j);
void swap(pair<int, int> x, pair<int, int> y);
int countUpDown(int i, int j);
int countLeftRight(int i, int j);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			compareBig(i, j);
			if(i < N-1) changeUpDown(i, j);
			if(j < N-1) changeLeftRight(i, j);
		}
	}

	cout << big;
}

void changeUpDown(int i, int j) {
	swap(make_pair(i, j), make_pair(i + 1, j));
	compareBig(i, j);
	compareBig(i + 1, j);
	swap(make_pair(i, j), make_pair(i + 1, j ));
}
void changeLeftRight(int i, int j) {
	swap(make_pair(i, j), make_pair(i, j + 1));
	compareBig(i, j);
	compareBig(i, j + 1);
	swap(make_pair(i, j), make_pair(i, j + 1));
}

void compareBig(int i, int j) {
	if (!(i < N && j < N )) return;
	int c = countUpDown(i, j);
	if (big < c) big = c;
	c = countLeftRight(i, j);
	if (big < c) big = c;
}

void swap(pair<int, int> x, pair<int, int> y) {
	int temp = arr[x.first][x.second];
	arr[x.first][x.second] = arr[y.first][y.second];
	arr[y.first][y.second] = temp;
}

int countUpDown(int i, int j) {
	int length = 1;
	for (int fi = i - 1; fi >= 0; fi--) {
		if (arr[i][j] == arr[fi][j]) {
			length++;
			continue;
		}
		else {
			break;
		}
	}
	for (int fi = i + 1; fi < N; fi++) {
		if (arr[i][j] == arr[fi][j]) {
			length++;
			continue;
		}
		else {
			break;
		}
	}
	return length;
}

int countLeftRight(int i, int j) {
	int length = 1;
	for (int fj = j - 1; fj >= 0; fj--) {
		if (arr[i][j] == arr[i][fj]) {
			length++;
			continue;
		}
		else {
			break;
		}
	}
	for (int fj = j + 1; fj < N; fj++) {
		if (arr[i][j] == arr[i][fj]) {
			length++;
			continue;
		}
		else {
			break;
		}
	}
	return length;
}