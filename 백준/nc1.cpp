#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* p0, * p1;
	int lastVisit;
};

vector<string> inputs = { "000", "1110", "01", "001", "110" , "11" };
int main() {

	Node* root = nullptr;
	for (int i = 0; i < inputs.size(); i++) {
		int ans;
		if (root == nullptr) {
			root = new Node();
			root->lastVisit = 0;
		}

		Node* current = root;
		ans = current->lastVisit;
		current->lastVisit = i + 1;
		for (int j = 0; j < inputs[i].length(); j++) {
			if (inputs[i][j] == '0') {
				if (current->p0 == nullptr) {
					current->p0 = new Node();
					current->p0->lastVisit = i + 1;
					current = current->p0;
				}
				else {
					current = current->p0;
					ans = current->lastVisit;
					current->lastVisit = i + 1;
				}
			}
			else {
				if (current->p1 == nullptr) {
					current->p1 = new Node();
					current->p1->lastVisit = i + 1;
					current = current->p1;
				}
				else {
					current = current->p1;
					ans = current->lastVisit;
					current->lastVisit = i + 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}