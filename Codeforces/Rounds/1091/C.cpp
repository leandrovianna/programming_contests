// Codeforces - New Year and the Sphere Transmission - 1091C
#include <bits/stdc++.h>
using namespace std;

int64_t get_value(int64_t k, int64_t n) {
    int64_t v = 0, x, i = 0;
    do {
        x = (n - 1 - i) / k;
        v += (x * (x+1)) / 2 * k + (x+1) * (i+1);
        i = i + (x+1) * k - n;
    } while (i != 0);
    return v;
}

int main() {
    int64_t n;

    cin >> n;

    set<int64_t> answers;

    for (int k = 1; k * k <= n; k++) {
        if (n % k != 0) continue;

        answers.insert(get_value(k, n));
        answers.insert(get_value(n/k, n));
    }

    for (const auto &x : answers) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
