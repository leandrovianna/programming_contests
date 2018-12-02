// AtCoder - Beginner Contest - Maximize the Formula - A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x[3];
    int ans = 0, y;

    cin >> x[0] >> x[1] >> x[2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                continue;
            for (int k = 0; k < 3; k++) {
                if (j == k || k == i)
                    continue;

                y = (x[i] * 10 + x[j]) + x[k];
                ans = max(y, ans);

                y = x[i] + (x[j] * 10 + x[k]);
                ans = max(y, ans);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
