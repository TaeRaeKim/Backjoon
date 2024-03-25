#include <bits/stdc++.h>
using namespace std;

class Node {
public :
	Node* left, * right;
	int value;
};

int t;
Node* root = nullptr;

void insert(Node*, Node*, int);
void print(Node*);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> t) {
		insert(root, nullptr, t);
	}
	print(root);

	return 0;
}

void insert(Node* node, Node* parent, int value) {
	if (node == nullptr) {
		node = new Node();
		node->value = value;

		if (parent == nullptr) root = node;
		else if (parent->value > value)	parent->left = node;
		else parent->right = node;
	}
	else {
		if (node->value > value) insert(node->left, node, value);
		else insert(node->right, node, value);
	}
}
void print(Node* node) {
	if (node == nullptr) return;
	print(node->left);
	print(node->right);
	cout << node->value << '\n';
}