// Codeforces - The Doors - 1143A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int l0 = -1, l1 = -1;

    cin >> n;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == 0)
            l0 = i;
        else
            l1 = i;
    }

    cout << min(l0, l1) + 1 << endl;
    return 0;
}
