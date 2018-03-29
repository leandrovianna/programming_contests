//Codeforces - Perdido em Marte - 1986
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, x;
    string out;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> hex >> x;
        out += (char)x;
    }

    cout << out << endl;

    return 0;
}
