// CS Academy - Three Ones - Round 84
#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 100 * 1000 + 10;
int a[N];

bool check(int x, int n) {
    assert(x <= n);
    int count = 0;
    for (int i = 0; i < x; i++) {
        if (a[i] == 1)
            count++;
    }

    for (int i = x; i < n; i++) {
        if (count < 3)
            return false;

        if (a[i-x] == 1)
            count--;

        if (a[i] == 1)
            count++;
    }

    if (count < 3)
        return false;

    return true;
}

int main() {
    int n;
    char aux;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        a[i] = aux - '0';
    }

    int lo = 3;
    int hi = n;
    int mid, ans = n;

    while (lo <= hi) {
        mid = (lo+hi) / 2;

        if (check(mid, n)) {
            hi = mid-1;
            ans = mid;
        } else {
            lo = mid+1;
        }
    }

    cout << ans << endl;
    return 0;
}
