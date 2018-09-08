// Codeforces - Function Height - 1036A - EduRound
#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k;

    cin >> n >> k;

    int64_t ans = k / n;
    if (k % n > 0)
        ans++;

    cout << ans << endl;
    return 0;
}
