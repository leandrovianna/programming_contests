// Codeforces - Beautiful Graph - 1093D - Edu Round
#include <bits/stdc++.h>
using namespace std;

const int N = 3 * 100100;
vector<int> g[N];
int color[N], cnt1, cnt2;

bool dfs(int v, int c) {
    if (color[v] != 0) {
        return color[v] != c;
    }

    color[v] = (c == 1 ? 2 : 1);
    if (color[v] == 1)
        cnt1++;
    else
        cnt2++;

    bool is_bip = true;

    for (const auto &u : g[v]) {
        if (!dfs(u, color[v])) {
            is_bip = false;
        }
    }

    return is_bip;
}

int64_t fat[N], inv[N]; // inverse of factorial of i

int64_t calc(int x, int64_t mod) {
    int64_t sum = 0;
    for (int i = 0; i <= x; i++) {
        sum = (sum + ((fat[x] * inv[x-i]) % mod) * inv[i]) % mod;
    }

    return sum;
}

pair<int64_t, int64_t> extendedEuclids(int64_t a, int64_t b) {
    if (b == 0) {
        return {1, 0};
    } else {
        auto p = extendedEuclids(b, a % b);
        return {p.second,
            p.first - floor((double)a / b) * p.second};
    }
}

int64_t inverseMod(int64_t a, int64_t n) {
    auto p = extendedEuclids(a, n);
    return (p.first % n + n) % n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int64_t mod = 998244353;
    int t, n, m, a, b;

    inv[0] = 1;
    fat[0] = 1;
    for (int i = 1; i < N; i++) {
        fat[i] = (fat[i-1] * i) % mod;
        inv[i] = inverseMod(fat[i], mod);
    }

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int v = 1; v <= n; v++) {
            color[v] = 0;
            g[v].clear();
        }

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int64_t ans = 1;

        for (int v = 1; v <= n; v++) {
            if (color[v] == 0) {
                cnt1 = 0;
                cnt2 = 0;
                if (dfs(v, 1)) {
                    ans = (ans * (calc(cnt1, mod) + calc(cnt2, mod)) % mod) % mod;
                } else {
                    ans = 0;
                    break;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
