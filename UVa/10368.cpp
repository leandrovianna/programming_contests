//UVa - Euclid's Game - UVA 10368
#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b, bool x) {
    if (b > a) {
        swap(b, a);
    }

    assert(a >= b);

    if (a % b == 0)
        return x;

    if (solve(a % b, b, !x) == x) {
        return x;
    } else if (a / b > 1 && solve(a % b + b, b, !x) == x) {
        return x;
    } else {
        return !x;
    }
}

int main() {
    ios::sync_with_stdio(false);

    int x, y;
    while (cin >> x >> y, x || y) {
        if (solve(x, y, true))
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;
    }
    return 0;
}
