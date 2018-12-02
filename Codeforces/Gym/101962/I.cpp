#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;
int64_t h[N], d1[N], d2[N];

int64_t tree1[4*N], tree2[4*N];

void build(int64_t tree[], int idx, int l, int r, int64_t v[]) {
    if (l == r)
        tree[idx] = v[l];
    else {
        int mid = (l + r) / 2;
        build(tree, 2*idx+1, l, mid, v);
        build(tree, 2*idx+2, mid+1, r, v);
        tree[idx] = max(tree[2*idx+1], tree[2*idx+2]);
    }
}

void update(int64_t tree[], int idx, int l, int r, int i, int64_t v) {
    if (i < l || i > r)
        return;

    if (l == r && l == i) {
        tree[idx] = v;
    } else {
        int mid = (l + r) / 2;
        update(tree, 2*idx+1, l, mid, i, v);
        update(tree, 2*idx+2, mid+1, r, i, v);

        tree[idx] = max(tree[2*idx+1], tree[2*idx+2]);
    }
}

int64_t query(int64_t tree[], int idx, int l, int r, int x, int y) {
    if (y < l || x > r)
        return 0;

    if (x <= l && r <= y) {
        return tree[idx];
    } else {
        int mid = (l + r) / 2;
        return max(query(tree, 2*idx+1, l, mid, x, y), query(tree, 2*idx+2, mid+1, r, x, y));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    d1[0] = 0;
    for (int i = 1; i < n; i++) {
        d1[i] = abs(h[i] - h[i-1]);
    }

    build(tree1, 0, 0, n-1, d1);

    d2[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        d2[i] = abs(h[i] - h[i+1]);
    }

    build(tree2, 0, 0, n-1, d2);

    int64_t height, v;
    int lo, hi, mid, ans1, ans2;
    for (int qi = 0, type, i; qi < q; qi++) {
        cin >> type;
        cin >> i >> height;
        i--;

        switch (type) {
            case 1:
                h[i] = height;
                update(tree1, 0, 0, n-1, i, abs(h[i] - h[i-1]));
                if (i < n-1)
                    update(tree1, 0, 0, n-1, i+1, abs(h[i+1] - h[i]));

                update(tree2, 0, 0, n-1, i, abs(h[i] - h[i+1]));
                if (i > 0)
                    update(tree2, 0, 0, n-1, i-1, abs(h[i-1] - h[i]));
                break;
            case 2:
                lo = 0;
                hi = i-1;
                ans1 = 0;

                while (lo <= hi) {
                    mid = (hi - lo) / 2 + lo;

                    v = query(tree2, 0, 0, n-1, mid, i-1);
                    if (v <= height) {
                        ans1 = max(ans1, i - 1 - mid + 1);
                        hi = mid-1; 
                    } else {
                        lo = mid+1;
                    }
                }

                lo = i+1;
                hi = n-1;
                ans2 = 0;

                while (lo <= hi) {
                    mid = (hi - lo) / 2 + lo;

                    v = query(tree1, 0, 0, n-1, i+1, mid);
                    if (v <= height) {
                        ans2 = max(ans2, mid - (i + 1) + 1);
                        lo = mid+1;
                    } else {
                        hi = mid-1;
                    }
                }

                cout << 1 + ans1 + ans2 << "\n";
                break;
        }
    }

    return 0;
}
