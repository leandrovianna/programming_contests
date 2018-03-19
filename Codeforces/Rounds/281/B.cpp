//Codeforces - Nearest Fraction - 281B Div2
#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    return __gcd(x,y);
}

int main() {
    ios::sync_with_stdio(false);
    const int N = 100000;
    const double EPS = 1e-9;

    int x, y, n;
    cin >> x >> y >> n;

    pair<int, int> ans;
    double nf = N, local_nf;

    if (n >= y) {
        ans = {x / gcd(x,y), y / gcd(x,y)};
    } else {
        for (int b = 1; b <= n; b++) {
            int lo = 0;
            int hi = N;
            int mid;

            while (lo <= hi) {
                mid = (lo + hi) >> 1;
                local_nf = (double) x / y - (double) mid / b;

                // verificando resultado global
                if (abs(local_nf) < nf || (abs(local_nf - nf) < EPS &&
                            (ans.second > b || (ans.second == b && ans.first > mid)))) {
                    nf = abs(local_nf);
                    ans.first = mid;
                    ans.second = b;
                    // cout << mid << "/" << b << endl;
                }

                // tentando aproximar mid/b de x/y
                if (local_nf < 0) {
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            }
        }
    }

    cout << ans.first << "/" << ans.second << endl;
    return 0;
}
