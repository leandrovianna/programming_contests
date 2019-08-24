// Codeforces - Array and segments (Hard Version) - 1108E2 - Div3
#include <bits/stdc++.h>
using namespace std;
 
const int M = 310, N = 100100, inf = 1000000000;
pair<int, int> seg[M];
int a[N];
 
pair<int, int> tree[4*N];
int lazy[4*N];
 
pair<int, int> combine(pair<int, int> &a, pair<int, int> &b) {
    return {min({a.first, a.second, b.first, b.second}),
            max({a.first, a.second, b.first, b.second})};
}
 
void lazy_update(int idx, int l, int r) {
    tree[idx].first += lazy[idx];
    tree[idx].second += lazy[idx];
 
    // push
    if (l != r) {
        lazy[2*idx+1] += lazy[idx];
        lazy[2*idx+2] += lazy[idx];
    }
 
    lazy[idx] = 0;
}
 
void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = {a[l], a[r]};
        lazy[idx] = 0;
    } else {
        int mid = (l + r) >> 1;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);
        tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
    }
}
 
void update(int idx, int l, int r, int x, int y, int val) {
    if (lazy[idx] != 0) {
        lazy_update(idx, l, r);
    }
 
    if (y < l || x > r)
        return;
 
    if (x <= l && r <= y) {
        lazy[idx] = val;
        lazy_update(idx, l, r);
    } else {
        int mid = (l + r) >> 1;
        update(2*idx+1, l, mid, x, y, val);
        update(2*idx+2, mid+1, r, x, y, val);
 
        tree[idx] = combine(tree[2*idx+1], tree[2*idx+2]);
    }
}
 
pair<int, int> query(int idx, int l, int r, int x, int y) {
    if (lazy[idx] != 0) {
        lazy_update(idx, l, r);
    }
 
    if (y < l || x > r)
        return {inf, -inf};
 
    if (x <= l && r <= y) {
        return tree[idx];
    } else {
        int mid = (l + r) >> 1;
        auto a = query(2*idx+1, l, mid, x, y);
        auto b = query(2*idx+2, mid+1, r, x, y);
 
        return combine(a, b);
    }
}
 
int test(int exclude, int n, int m) {
    for (int i = 0; i < m; i++) {
        if (seg[i].first <= exclude && exclude <= seg[i].second) {
            update(0, 0, n-1, seg[i].first, seg[i].second, -1);
        }
    }
 
    pair<int, int> x = query(0, 0, n-1, 0, n-1);
 
    for (int i = 0; i < m; i++) {
        if (seg[i].first <= exclude && exclude <= seg[i].second) {
            update(0, 0, n-1, seg[i].first, seg[i].second, +1);
        }
    }
 
    return x.second - x.first;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
 
    cin >> n >> m;
 
    int mi = inf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mi = min(mi, a[i]);
    }
 
    build(0, 0, n-1);
 
    set<int> candidates;
    for (int i = 0; i < m; i++) {
        cin >> seg[i].first >> seg[i].second;
        seg[i].first--;
        seg[i].second--;
 
        candidates.insert(seg[i].first);
        candidates.insert(seg[i].second);
    }
 
    auto y = query(0, 0, n-1, 0, n-1);
    int d = y.second - y.first;
    int besti = -1;
 
    for (const auto &i : candidates) {
        int e = test(i, n, m);
 
        if (d < e) {
            d = e;
            besti = i;
        }
    }
 
    vector<int> indexes;
    if (besti != -1) {
        for (int i = 0; i < m; i++) {
            if (seg[i].first <= besti && besti <= seg[i].second) {
                indexes.push_back(i);
            }
        }
    }
 
    cout << d << "\n";
    cout << indexes.size() << "\n";
    for (const auto &idx : indexes) {
        cout << idx+1 << " ";
    }
    cout << "\n";
 
    return 0;
}
