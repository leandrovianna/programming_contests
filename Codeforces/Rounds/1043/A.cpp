#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 110;
    int n, a[N], maxa = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    for (int k = maxa; k <= 10000; k++) {
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; i++) {
            count1 += k - a[i];
            count2 += a[i];
        }

        if (count1 > count2) {
            cout << k << endl;
            return 0;
        }
    }

    return 0;
}
