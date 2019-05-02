// UVA - 10107 - What is the Median?
#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 10010;
    int x, a[N], k;

    while (cin >> x) {
        a[k++] = x;
        for (int i = k-1; i > 0; i--) {
            if (a[i] < a[i-1]) {
                swap(a[i], a[i-1]);
            } else {
                break;
            }
        }

        if (k % 2)
            cout << a[k/2] << "\n";
        else
            cout << (a[k/2] + a[k/2-1]) / 2 << "\n";
    }
    return 0;
}
