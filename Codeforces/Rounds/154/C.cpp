// Codeforces - Double Profiles - 154C
#include <bits/stdc++.h>
using namespace std;

const int N = 1000100;
vector<int> v[N];
vector<pair<int, int>> edges;
uint64_t ppow[N], hv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;
    
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;

        edges.push_back({x, y});
        v[x].push_back(y);
        v[y].push_back(x);
    }

    map<uint64_t, int64_t> cnt;

    const uint64_t mod = (1LL << 60) - 1;
    const uint64_t p = 101869;

    ppow[0] = 1;
    for (int i = 1; i < N; i++) {
        ppow[i] = (ppow[i-1] * p) % mod;
    }

    for (int i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end());

        hv[i] = 0;
        int j = 0;
        for (const auto &u : v[i]) {
            hv[i] = (hv[i] + (u+1) * ppow[j]) % mod;
            j++;
        }

        cnt[hv[i]]++;
    }

    int64_t answer = 0;
    // count vertices with neighborhood equal that do not have edge between themselves
    for (const auto &p : cnt) {
        answer += (p.second * (p.second - 1)) / 2;
    }

    for (int x = 0; x < n; x++) {
        v[x].push_back(x);
        sort(v[x].begin(), v[x].end());

        hv[x] = 0;
        int j = 0;
        for (const auto &u : v[x]) {
            hv[x] = (hv[x] + (u+1) * ppow[j]) % mod;
            j++;
        }
    }

    // count the same from above, but for vertices with edges between themselves
    for (const auto &e : edges) {
        int x = e.first,
            y = e.second;
        if (v[x].size() != v[y].size())
            continue;

        if (hv[x] == hv[y]) {
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}
