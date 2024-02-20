#include <iostream>
using namespace std;


class LinkedList {
public :
	static LinkedList* node;
	LinkedList* prev;
	LinkedList* next;
	static int size;
	LinkedList();
	void push(int);
	int kpop(int);
	void print();
	int empty() { return (node == nullptr); }
private:
	int value;
};

LinkedList* LinkedList::node = nullptr;
int LinkedList::size = 0;

LinkedList::LinkedList() {
}

void LinkedList::push(int value) {
	LinkedList* temp = new LinkedList();
	temp->value = value;
	if (node == nullptr) {
		node = temp;
		node->prev = temp;
		node->next = temp;
	}
	else {
		LinkedList* prev = node->prev;
		prev->next = temp;
		temp->prev = prev;
		temp->next = node;
		node->prev = temp;
	}
	size++;
}
int LinkedList::kpop(int k) {
	for (int i = 0; i < k - 1; i++) {
		node = node->next;
	}
	int value = node->value;

	LinkedList* temp = node;
	node = node->next;
	temp->prev->next = node;
	node->prev = temp->prev;
	delete temp;
	if (size == 1) node = nullptr;
	

	size--;
	return value;
}
void LinkedList::print() {
	LinkedList* temp = node;
	do {
		cout << temp->value << ' ';
	} while ( node != (temp = temp->next));
	
	cout << endl;
}

int main() {
	LinkedList l;
	int N, K;
	cin >> N >> K;

	
	for (int i = 1; i <= N; i++) {
		l.push(i);
	}
	cout << '<';
	while (!l.empty()) {
		if (l.size == 1) {
			cout << l.kpop(K);
			break;
		}
		cout << l.kpop(K) << ", ";
	}
	cout << '>' << '\n';

	return 0;
}