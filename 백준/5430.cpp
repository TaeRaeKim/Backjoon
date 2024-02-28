#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	string p;
	bool fb = true;//true일때 앞에서 버리기
	int fc, bc, N;
	int arr[100000];
	string inputArr = "";
	for (int tc = 0; tc < TC; tc++) {
		fc = 0; bc = 0;
		fb = true;
		cin >> p;
		cin >> N;
		cin >> inputArr;

		string tm = "";
		int idx = 0;
		int tdx = 0;

		while (inputArr[tdx] != ']') {
			if (inputArr[tdx] == '[')
				tdx++;
			else if (inputArr[tdx] == ',') {
				arr[idx] = stoi(tm);
				idx++;
				tdx++;
				tm = "";
			}
			else {
				tm += inputArr[tdx]; 
				tdx++;
			}
		}
		if (tm != "") {
			arr[idx] = stoi(tm);
			idx++;
			tm = "";
		}

		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				fb = !fb;
			}
			else {
				if (fb) fc++;
				else bc++;
			}
		}
		if (fb) {
			if (fc > N - bc) {
				cout << "error\n";
				continue;
			}
			cout << '[';
			for (int i = fc; i < N - bc; i++) {
				cout << arr[i];
				if (i != N - bc - 1) cout << ',';
			}
			cout << "]\n";
		}
		else {
			if (N - bc < fc) {
				cout << "error\n";
				continue;
			}
			cout << '[';
			for (int i = N - bc - 1; i >= fc; i--) {
				cout << arr[i];
				if (i != fc) cout << ',';
			}
			cout << "]\n";
		}
	}
	return 0;
}