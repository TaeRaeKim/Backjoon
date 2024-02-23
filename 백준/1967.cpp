//4시부터 한시간진행중
// 아마 30분더 걸리듯
// 일단 중지

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
	/// 입력 , node 세팅까지 완료
	/// 전위(or후위) 순회 하며 left right 값 업데이트 
	/// 중위 순회 하며 parent 값 업데이트
	/// 
	/// 이후 [1] ~ [N]까지 돌며 세값중 두값이 가장 큰 노드가 정답
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