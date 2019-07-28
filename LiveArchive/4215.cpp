// Live Archive - 4215 - Feynman
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int64_t t[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    t[0] = 0;
    for (int64_t i = 1; i < N; i++) {
        t[i] = t[i-1] + i * i;
    }

    int n;
    while (cin >> n, n) {
        cout << t[n] << "\n";
    }

    return 0;
}
