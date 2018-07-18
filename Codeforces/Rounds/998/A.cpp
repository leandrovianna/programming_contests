// Codeforces - Ballons - 998A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100;
    int n, a[N];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int mask = 1; mask < (1 << n)-1; mask++) {
        int sum1 = 0, sum2 = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            if ((1 << i) & mask) {
                sum1 += a[i];
                cnt++;
            } else {
                sum2 += a[i];
            }
        }

        if (sum1 != sum2) {
            cout << cnt << "\n";
            for (int i = 0; i < n; i++) {
                if ((1 << i) & mask)
                    cout << i+1 << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}
