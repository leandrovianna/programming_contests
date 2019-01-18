#include <bits/stdc++.h>
using namespace std;

string s;
double v, ans;
unordered_map<string, double> currency;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, c, n;

    cin >> t;
    while (t--) {
        cin >> c >> n;
        for (int i = 0; i < c; i++) {
            cin >> s >> v;
            currency[s] = v;
        }

        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> v >> s;
            if (s == "JD") {
                ans += v;
            } else {
                ans += currency[s] * v;
            }
        }

        cout << fixed << setprecision(6);
        cout << ans << '\n';
    }
    return 0;
}
