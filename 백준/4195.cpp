#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Person {
public:
	string name;
	int relation;
	Person() {
		name = "";
		relation = 0;
	}
	Person(string name, int relation) {
		this->name = name;
		this->relation = relation;
	}
};
unordered_map<string, Person> hashmap;

string find(string v) {
	if (hashmap[v].name == v) return v;
	hashmap[v].name = find(hashmap[v].name);
	return hashmap[v].name;
}
void uniom(string u, string v){
	u = find(u);
	v = find(v);
	if (u == v) return;
	hashmap[u].name = v;
	hashmap[v].relation += hashmap[u].relation;
}

void init(string a, string b) {
	if (hashmap.find(a) == hashmap.end()) hashmap.insert(make_pair(a, Person(a, 1)));;
	if (hashmap.find(b) == hashmap.end()) hashmap.insert(make_pair(b, Person(b, 1)));;
}

int TC, N;
string a, b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N;
		hashmap.clear();
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			init(a, b);
			uniom(a, b);
			cout << hashmap[find(b)].relation << '\n';
		}
	}

	return 0;
}