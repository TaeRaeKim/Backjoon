#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	Node *left, *right;
	char value;
	Node();
	Node(char);
	void printPre();
	void printIn();
	void printPost();
};

char arr[26][2];
int N;
queue<Node*> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	char key, left, right;
	for (int i = 0; i < N; i++) {
		cin >> key >> left >> right;
		arr[key - 'A'][0] = (left != '.' ? (left-'A') : 0);
		arr[key - 'A'][1] = (right != '.' ? (right-'A') : 0);
	}

	Node* head = new Node('A');
	Node* node = head;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		key = node->value-'A';
		q.pop();
		left = arr[key][0];
		right = arr[key][1];
		if (left) {
			node->left = new Node(left + 'A');
			q.push(node->left);
		}
		if (right) {
			node->right = new Node(right + 'A');
			q.push(node->right);
		}
	}

	head->printPre();
	cout << '\n';
	head->printIn();
	cout << '\n';
	head->printPost();

	return 0;
}

Node::Node() {
	left = nullptr;
	right = nullptr;
	value = 0;
}
Node::Node(char value) {
	Node();
	this->value = value;
}

void Node::printPre() {
	cout << value;
	if (left != nullptr) left->printPre();
	if (right != nullptr) right->printPre();
}
void Node::printIn() {
	if (left != nullptr) left->printIn();
	cout << value;
	if (right != nullptr) right->printIn();
}
void Node::printPost() {
	if (left != nullptr) left->printPost();
	if (right != nullptr) right->printPost();
	cout << value;
}