#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A, B;
    cin >> A >> B;
    char c;
    if (A > B) c = '>';
    else if (A < B) c = '<';
    else c = '=';
    if (c == '=') cout << "== \n";
    else cout << c << '\n';
    return 0;
}

