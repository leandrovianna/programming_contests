// Codeforces - Carry Cam Failure - 102433L
#include <bits/stdc++.h>
using namespace std;

const int D = 30;
int num[D], num2[D];

int calc(int idx) {
    int d = 0;
    for (int k = 0; k <= idx; k++) {
        d += (num2[k] * num2[idx-k]) % 10;
    }
    d %= 10;
    return d;
}

bool backtrack(int i, int m, int k) {
    if (i == k) {
        return true;
    }

    if (i >= m) {
        if (calc(i) == num[i] && backtrack(i+1, m, k))
            return true;
    } else {
        for (int x = 0; x < 10; x++) {
            num2[i] = x;

            int d = calc(i);
            if (d == num[i]) {
                if (backtrack(i+1, m, k))
                    return true;
            }
        }
        num2[i] = 0;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k = 0;
    char ch;
    while (cin >> ch) {
        num[k++] = ch - '0';
    }

    const int m = (k+1) / 2;
    if (k % 2 == 1 && backtrack(0, m, k)) {
        for (int i = 0; i < m; i++) {
            cout << num2[i];
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}
