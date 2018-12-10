// Codeforces - Kvass and the Fair Nut - 1084B Div2
#include <bits/stdc++.h>
using namespace std;

int64_t teto(int64_t x, int64_t y) {
    return (x+y-1) / y;
}

int main() {
    int64_t n, s, mini, sum, x;

    cin >> n >> s;

    mini = 1e10;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mini = min(mini, x);
        sum += x;
    }

    int64_t v = sum - n * mini;

    if (s <= v) {
        cout << mini << endl;
    } else if (s > sum) {
        cout << "-1" << endl;
    } else {
        cout << (mini - teto(s - v, n)) << endl;
    }
    return 0;
}
