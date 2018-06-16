// Codeforces - Fingerprints - 994A Div2
#include <bits/stdc++.h>
using namespace std;

int cnt[20];

int main() {
    int n, m;
    int seq[20];

    cin >> n >> m;

    for (int i = 0;  i < n; i++) {
        cin >> seq[i];
    }

    for (int i = 0, x; i < m; i++) {
        cin >> x;
        cnt[x] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (cnt[seq[i]] == 1)
            cout << seq[i] << " ";
    }
    cout << "\n";

    return 0;
}
