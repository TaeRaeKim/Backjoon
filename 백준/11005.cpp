#include <bits/stdc++.h>
using namespace std;

int N, B, m, i;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> B;
    while (N >= (long long int)pow(B, i)) i++;

    for (i = i - 1; i >= 0; i--) {
        m = N / pow(B, i);
        if (m >= 10)  cout << (char)('A' + m - 10);
        else cout << (char)('0' + m);
        N %= (int)pow(B, i);
    }
    return 0;
}