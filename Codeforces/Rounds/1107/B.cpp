// Codeforces - Digital Root - 1107B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int64_t k, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k >> x;

        cout << (k - 1) * 9LL + x << "\n";
    }
    return 0;
}
