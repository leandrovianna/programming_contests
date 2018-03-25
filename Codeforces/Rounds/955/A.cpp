//Codeforces - Feed the Cat - 955A Div2
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int hh, mm;

    cin >> hh >> mm;

    int h, d, c, n;

    cin >> h >> d >> c >> n;

    double ans = DBL_MAX;
    int hunger = h;
    for (int i = hh; i <= 23; i++) {
        for (int j = (i == hh ? mm : 0); j <= 59; j++) {
            double cost = ceil(hunger / (double) n) * c;
            if (i >= 20)
                cost *= 0.8;

            // cout << i << ":" << j << ", cost = " << cost << endl;
            ans = min(ans, cost);

            hunger += d;
        }
    }

    cout << fixed << setprecision(4) << ans << endl;

    return 0;
}
