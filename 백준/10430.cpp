#include <iostream>
using namespace std;

int main() {
    /*
    (A+B)%C�� ((A%C) + (B%C))%C �� ������?
    (A��B)%C�� ((A%C) �� (B%C))%C �� ������?
    */
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A + B) % C << endl;
    cout << ((A % C) + (B % C)) % C << endl;
    cout << (A*B) % C << endl;
    cout << ((A % C) *(B % C)) % C << endl;
}