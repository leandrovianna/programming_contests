// TAP 2018/2 - Bolinhas de Gude - B4
#include <bits/stdc++.h>
using namespace std;

int calc_mex(unordered_set<int> &nimbers) {
    int mex = 0;
    while (nimbers.find(mex) != nimbers.end()) {
        mex++;
    }

    return mex;
}

const int N = 110, M = 100;
int memo[N][N];

int grundy(int l, int c) {
    if (memo[l][c] != -1)
        return memo[l][c];

    if (l == 0 || c == 0 || l == c)
        return M * M + M;

    unordered_set<int> nimbers;

    for (int u = 1; u <= M; u++) {
        if (l - u >= 0)
            nimbers.insert(grundy(l - u, c));

        if (c - u >= 0)
            nimbers.insert(grundy(l, c - u));

        if (l - u >= 0 && c - u >= 0)
            nimbers.insert(grundy(l - u, c - u));
    }

    return memo[l][c] = calc_mex(nimbers);
}

int main() {
    int n, ans = 0;

    cin >> n;

    memset(memo, -1, sizeof(memo));

    for (int i = 0, l, c; i < n; i++) {
        cin >> l >> c;
        ans ^= grundy(l, c);
    }

    cout << (ans > 0 ? "Y" : "N") << endl;
    return 0;
}
