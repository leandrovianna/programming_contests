// Codeforces - Partition - 946A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int b = 0, c = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x <= 0)
            c += x;
        else
            b += x;
    }

    cout << b - c << "\n";
    return 0;
}
