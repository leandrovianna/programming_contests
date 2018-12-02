// Codeforces - Pick Heroes - 1056C
#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int p[N], match[N];

int main() {
    int n, m;
    set<int> available;

    cin >> n >> m;

    for (int i = 1; i <= 2*n; i++) {
        cin >> p[i];
        available.insert(i);
    }

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        match[a] = b;
        match[b] = a;
    }

    int t, x;
    cin >> t;
    t--;

    int y = -1;
    for (int qi = 0; qi < 2*n; qi++) {
        if (t == 0) {
            if (y != -1) {
                cout << y << endl;
                available.erase(y);
                y = -1;
            } else {
                int mx = 0, i = -1;
                for (const auto &x : available) {
                    if (match[x] != 0 && mx < p[x]) {
                        i = x;
                        mx = p[x];
                    }
                }

                if (i == -1) {
                    for (const auto &x : available) {
                        if (mx < p[x]) {
                            i = x;
                            mx = p[x];
                        }
                    }
                }

                cout << i << endl;
                available.erase(i);
            }
        } else {
            cin >> x;
            if (x == -1)
                break;
            available.erase(x);
            if (available.count(match[x])) {
                y = match[x];
            }
        }
        t = !t;
    }

    return 0;
}
