// Codeforces - Reachable Numbers - 1157A Div 3
#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    x++;
    while (x % 10 == 0) {
        x /= 10;
    }
    return x;
}

int main() {
    int n;
    set<int> ss;

    cin >> n;

    int ans = 0;
    do {
        ss.insert(n);
        n = f(n);
        ans++;
    } while (ss.find(n) == ss.end());

    cout << ans << endl;
    return 0;
}
