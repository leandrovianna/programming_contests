// Codeforces - Destroying Array - 722C
#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int a[N], b[N];
bool enab[N];

struct UnionFind {
    int p[N], s[N];
    int64_t sum[N];
    void init(int n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
            s[i] = 1;
        }
    }

    int find(int x) {
        if (p[x] == x) return x;
        else return p[x] = find(p[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return ;

        if (s[x] > s[y]) {
            p[y] = x;
            s[x] += s[y];
            sum[x] += sum[y];
        } else {
            p[x] = y;
            s[y] += s[x];
            sum[y] += sum[x];
        }
    }
} uf;

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    uf.init(n);

    vector<int64_t> answer;
    int64_t maxsum = 0;
    for (int i = n-1; i >= 0; i--) {
        answer.push_back(maxsum);

        uf.sum[b[i]] = a[b[i]];
        enab[b[i]] = true;

        if (b[i]-1 >= 0 && enab[b[i]-1]) {
            uf.join(b[i], b[i]-1);
        }

        if (b[i]+1 < n && enab[b[i]+1]) {
            uf.join(b[i], b[i]+1);
        }

        maxsum = max(maxsum, uf.sum[uf.find(b[i])]);
    }

    reverse(answer.begin(), answer.end());

    for (const auto &x : answer) {
        cout << x << "\n";
    }

    return 0;
}
