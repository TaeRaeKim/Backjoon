//4�ú��� �ѽð�������
// �Ƹ� 30�д� �ɸ���
// �ϴ� ����

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	static int size;
	Node *pp, *lp, *rp;
	int p, l, r;
	Node();
};

Node node[10000];
vector<map<int,int>> weight(10001);
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int s, e, w;

	// N*2+@;
	for (int i = 0; i < N-1; i++) {
		cin >> s >> e >> w;
		if (node[s].lp == nullptr) {
			node[s].lp = &node[e];
			node[s].l = w;
		}
		else {
			node[s].rp = &node[e];
			node[s].r = w;
		}
		node[e].pp = &node[s];
	}
	/// <summary>
	/// �Է� , node ���ñ��� �Ϸ�
	/// ����(or����) ��ȸ �ϸ� left right �� ������Ʈ 
	/// ���� ��ȸ �ϸ� parent �� ������Ʈ
	/// 
	/// ���� [1] ~ [N]���� ���� ������ �ΰ��� ���� ū ��尡 ����
	/// </summary>

	return 0;
}

int Node::size = 0;
Node::Node() {
	pp = nullptr;
	lp = nullptr;
	rp = nullptr;
	p = 0;
	l = 0;
	r = 0;
}