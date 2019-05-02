// UVA - 11926 - Multitasking
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 1000010;
    int n, m;

    while (cin >> n >> m, n || m) {
        bitset<N> mask, aux;
        for (int i = 0, l, r; i < n; i++) {
            cin >> l >> r;
            aux.set(0) = 1;
            aux <<= r - l;
        }
        for (int i = 0, l, r, interval; i < m; i++) {
            cin >> l >> r >> interval;
        }
    }
    return 0;
}
