// TAP 2018/2 - Tree Routing - F1
#include <bits/stdc++.h>
using namespace std;

int lvl(int i) {
    return ceil(log2(i)) + 1;
}

int main() {
    const int N = 130;
    int n, x, a[N];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> x;

    int p1 = -1, p2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            if (p1 == -1)
                p1 = i;
            else
                p2 = i;
        }
    }

    int count = 0;
    while (lvl(p1) < lvl(p2)) {
        count++;
        p2 /= 2;
    }

    while (p1 / 2 != p2 / 2) {
    }
    return 0;
}
