//Codeforces - The Child and Set - 437B Div2
#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) {
    for (int i = 0; i < 20; i++) {
        if ((1 << i) & x)
            return 1 << i;
    }
    return 0;
}

int main() {
    const int N = 100000;
    int sum, limit;

    cin >> sum >> limit;

    int ans[N+10], k = 0;
    for (int x = limit; x >= 1; x--) {
        if (sum == 0)
            break;

        if (sum >= lowbit(x)) {
            ans[k++] = x;
            sum -= lowbit(x);
        }
    }

    if (sum > 0) {
        cout << -1 << endl;
    } else {
        cout << k << endl;
        for (int i = 0; i < k; i++) {
            cout << ans[i];
            if (i < k-1)
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
