// Codeforces - Determine Line - 1056A
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int cnt[N];

int main() {
    int n;
    cin >> n;

    for (int i = 0, r, x; i < n; i++) {
        cin >> r;
        for (int j = 0; j < r; j++) {
            cin >> x;
            cnt[x]++;
        }
    }

    for (int v = 1; v <= 100; v++) {
        if (cnt[v] == n)
            cout << v << " ";
    }
    cout << endl;
    return 0;
}
