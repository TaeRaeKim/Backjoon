#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

int main() {

	vector<pos> n;

	//n.push_back(1);
	//n.push_back(2);
	//n.push_back(3);
	//n.push_back(4);
	//n.push_back(5);
	//n.push_back(6);
	
	n.push_back(pos(1, 1));
	n.push_back(pos(1, 2));
	n.push_back(pos(1, 3));
	n.push_back(pos(2, 1));
	n.push_back(pos(2, 2));
	n.push_back(pos(2, 3));


	vector<int> ind;
	int k = 3;
	// k���� 1 �߰�
	for (int i = 0; i < k; i++) {
		ind.push_back(1);
	}

	//3 ��(6��-3��)�� 0 �߰�
	for (int i = 0; i < n.size() - k; i++) {
		ind.push_back(0);
	}

	// ����
	sort(ind.begin(), ind.end());

	//����
	do {
		// ���
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				cout << n[i].first << n[i].second << " ";
			}
		}

		printf("\n");

	} while (next_permutation(ind.begin(), ind.end()));

	return 0;

}