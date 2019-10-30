#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int tree[2][4*N];
int flag[2][4*N];

void build(int type, int idx, int l, int r) {
    if (l == r) {
        tree[type][idx] = 0;
        flag[type][idx] = 0;
    } else {
        int mid = (l + r) >> 1;
        build(type, idx * 2 + 1, l, mid);
        build(type, idx * 2 + 2, mid+1, r);
        tree[type][idx] = tree[type][2 * idx + 1] + tree[type][2 * idx + 2];
        flag[type][idx] = 0;
    }
}

void lazy_update(int type, int idx, int l, int r) {
    if (flag[type][idx] > 0) {
        tree[type][idx] += (r - l + 1) * flag[type][idx];

        if (l != r) {
            flag[type][2 * idx + 1] += flag[type][idx];
            flag[type][2 * idx + 2] += flag[type][idx];
        }

        flag[type][idx] = 0;
    }
}

void update(int type, int idx, int l, int r, int x, int y) {
    lazy_update(type, idx, l, r);

    if (x > r || y < l)
        return;

    if (x <= l && r <= y) {
        flag[type][idx] += 1;
        lazy_update(type, idx, l, r);
    } else {
        int mid = (l + r) >> 1;
        update(type, 2 * idx + 1, l, mid, x, y);
        update(type, 2 * idx + 2, mid+1, r, x, y);

        tree[type][idx] = tree[type][2 * idx + 1] + tree[type][2 * idx + 2];
    }
}

int query(int type, int idx, int l, int r, int x, int y) {
    lazy_update(type, idx, l, r);

    if (x > r || y < l)
        return 0;

    if (x <= l && r <= y) {
        return tree[type][idx];
    } else {
        int mid = (l + r) >> 1;
        int v1 = query(type, 2 * idx + 1, l, mid, x, y);
        int v2 = query(type, 2 * idx + 2, mid+1, r, x, y);

        return v1 + v2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, p, q;
    char d;

    cin >> t;
    for (int ti = 1; ti <= t; ti++) {
        cin >> p >> q;

        build(0, 0, 0, q); // x axis
        build(1, 0, 0, q); // y axis

        for (int i = 0, x, y; i < p; i++) {
            cin >> x >> y >> d;
            switch (d) {
                case 'N':
                    update(1, 0, 0, q, y+1, q);
                    break;
                case 'S':
                    update(1, 0, 0, q, 0, y-1);
                    break;
                case 'E':
                    update(0, 0, 0, q, x+1, q);
                    break;
                case 'W':
                    update(0, 0, 0, q, 0, x-1);
                    break;
            }
        }

        int minX = 0, minY = 0, cnt = 0;
        for (int i = 0; i <= q; i++) {
            int x = query(0, 0, 0, q, i, i);
            if (x > cnt) {
                cnt = x;
                minX = i;
            }
        }

        cnt = 0;
        for (int i = 0; i <= q; i++) {
            int x = query(1, 0, 0, q, i, i);
            if (x > cnt) {
                cnt = x;
                minY = i;
            }
        }

        cout << "Case #" << ti << ": " << minX << " " << minY << "\n";
    }
    return 0;
}
