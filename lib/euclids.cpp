// Euclids Algorithm
#include <bits/stdc++.h>
using namespace std;

pair<int, int> extendedEuclids(int a, int b) {
    if (b == 0) {
        return {1, 0};
    } else {
        auto p = extendedEuclids(b, a % b);
        return {p.second,
            p.first - floor((double)a / b) * p.second};
    }
}

int main() {
    ios::sync_with_stdio(false);

    return 0;
}
