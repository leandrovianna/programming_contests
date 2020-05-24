#include <bits/stdc++.h>
using namespace std;

const int N = 100100, E = 30;

namespace UF {
    int parent[N], size[N];
    void init() {
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void join(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return;

        if (size[x] >= size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
    }
}

struct node {
    int child[E];
    int end;

    node() {
        end = N;
        for (int i = 0; i < E; i++) {
            child[i] = -1;
        }
    }
};

int root[N];
string input[N];
vector<node> trie;
int memo[N];

void add_trie(int idx) {
    int g = UF::find(idx);
    int i = root[g];
    string s = input[idx];

    for (const auto &ch : s) {
        if (trie[i].child[ch - 'a'] == -1) {
            trie[i].child[ch - 'a'] = trie.size();
            trie.push_back(node());
        }

        i = trie[i].child[ch - 'a'];
    }

    trie[i].end = min(trie[i].end, idx);
}

int find_trie(int idx) {
    int g = UF::find(idx);
    int i = root[g];
    string s = input[idx];

    int ans = N;

    for (const auto &ch : s) {
        ans = min(ans, trie[i].end);
        i = trie[i].child[ch - 'a'];
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }

    cin >> m;

    UF::init();

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        UF::join(x, y);
    }

    set<int> groups;

    for (int i = 1; i <= n; i++) {
        groups.insert(UF::find(i));
    }

    for (const auto &i : groups) {
        root[i] = trie.size();
        trie.push_back(node());
    }

    for (int i = 1; i <= n; i++) {
        memo[i] = -1;
        add_trie(i);
    }

    cin >> q;

    for (int i = 0, x; i < q; i++) {
        cin >> x;
        int ans = find_trie(x);
        if (ans == N)
            ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
