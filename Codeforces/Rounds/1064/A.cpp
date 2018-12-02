// Codeforces - Make a triangle! - 1064A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    int ans = 1e9;
    for (int i = a; i <= a+110; i++) {
        for (int j = b; j <= b+110; j++) {
            for (int k = c; k <= c+110; k++) {
                if (i + j > k && i + k > j && j + k > i) {
                    ans = min(ans, (i + j + k) - (a + b + c));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
