// ���� ���۽ð� : 0926
// Ǯ�� �Ϸ�ð� : �𸣰���. ���ͷ����� ������ �ð��̾���.
// ������ Ǯ���°� : O
//

#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, K;
	cin >> N >> K;
	list<int> l;
	for (int i = 1; i <= N; i++) {
		l.push_back(i);
	}
	list<int>::iterator iter = l.begin();
	list<int>::iterator temp;

	cout << "<";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			if (j == K - 1) {
				if(i == N - 1)cout << *iter << ">";
				else cout << *iter << ", ";
				temp = iter;
				iter = next(iter);
				l.erase(temp);
			}
			else iter++;

			if (iter == l.end()) {
				iter = l.begin();
			}
		}
	}
	return 0;
}
