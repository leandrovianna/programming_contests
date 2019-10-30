// Spoj - Balloons - UFPT2015H
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
pair<pair<int, int>, int> con[N];

int main() {
    int n, a, b;

    while (cin >> n >> a >> b, n || a || b) {
        for (int i = 0; i < n; i++) {
            cin >> con[i].second
                >> con[i].first.first
                >> con[i].first.second;
        }

        sort(con, con+n, [](const auto &a, const auto &b) {
            return abs(a.first.first - a.first.second) 
                    > abs(b.first.first - b.first.second);
        });

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int da = con[i].first.first;
            int db = con[i].first.second;
            int k = con[i].second;

            while (k > 0) {
                if (da <= db) {
                    if (a > 0) {
                        a--;
                        //cout << "from a\n";
                        ans += da;
                    } else {
                        b--;
                        //cout << "from b\n";
                        ans += db;
                    }
                } else {
                    if (b > 0) {
                        b--;
                        //cout << "from b\n";
                        ans += db;
                    } else {
                        a--;
                        //cout << "from a\n";
                        ans += da;
                    }
                }

                k--;
            }
            
            //cout << "*" << ans << "\n";
        }

        cout << ans << "\n";
    }
    return 0;
}
